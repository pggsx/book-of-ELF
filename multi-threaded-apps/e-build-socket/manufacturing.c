/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef manufacturing_c
#define manufacturing_c

#include "mySocket.h" // For networking
#include <stdio.h>
#include <stdint.h>
#include "manufacturing.h"
#include "hardware.h"
#include "statemodel.h" // For the other states
#include <time.h> // For random seeding
#include <stdlib.h> // For random seeding
#include <string.h> // For strlen
// For Networking
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

//constant defintions for server-client process
#define MAX_CAPACITY 50
#define MAX_DURATION 5
#define MAX_ORDERSIZE 2000
#define MIN_CAPACITY 10
#define MIN_DURATION 1
#define MIN_ORDERSIZE 1000
#define MAX_CLI 3 // Number of lines
#define MAXBUFLEN 2560
#define PORT 137 // Service name/port number

// Create the object of the manufacturing state
state_t manufacturing = {
	default_event_handler,	// order recieved
	default_event_handler,	// payment validated
	default_event_handler,	// payment rejected
	factory_failed,		// factory fail
	factory_success,	// factory success
	default_event_handler,	// delivery success
	default_event_handler,	// delivery fail
	entry_to,		// entry
	exit_from		// exit
};

state_t* factory_failed()
{
	exit_from();
	updateStatus(FAIL);
	return &accepting;
}

state_t* factory_success()
{
	exit_from();
	updateStatus(SUCCESS);
	chargeClient();
	return &shipping;
}

void entry_to()
{
	printf("Factory status: MANUFACTURING\n");
	printf("Dispatching factory lines for order.\n");
	process_factory();
}

void exit_from()
{
	printf("Factory lines have been shut down.\n");
}

void process_factory()
{

	// Socket variables
	struct sockaddr_in fsin;   /* the from address of a client */
	int sock;               /* server socket */
	unsigned int alen;       /* from-address length */
	msgBuf client_msg;
	msgBuf server_msg;
	// Order property variables
	int ordersize = getOrdersize();
	int line_num = 1;
	int order_left = ordersize;
	int curr_line = 0;
	int active_cli = 0;
	int processing = 1;
	int capacity[4];
	int duration[4];
	int items[4];
	int iterations[4];
	int ii;

	sock = serverUDPsock(PORT); // Create the service

	// Wait and respond to clients 
	while (processing) 
	{
		alen = sizeof(fsin);
		//fprintf(stderr , "DEBUG: SERVER WAITING\n" );		
		if ( recvfrom( sock, &client_msg, MAXBUFLEN, 0, (SA *) &fsin, &alen ) < 0 )
		{
			err_sys( "recvfrom" ) ;
		}
		//fprintf(stderr, "DEBUG: SERVER RECIEVED\n" );

		// Process message
		//printf("DEBUG: Msg Type recieving: %d\n", client_msg.msg_type);
		//printf("DEBUG: Msg be_active: %d\n", client_msg.be_active);
		switch (client_msg.msg_type) {
			// Give client info
			case 1:
				server_msg.msg_type = 0;
				server_msg.line_num = line_num;
				server_msg.capacity = getCapacity();
				server_msg.duration = getDuration();
				capacity[line_num - 1] = server_msg.capacity;
				duration[line_num - 1] = server_msg.duration;
				items[line_num - 1] = 0;
				iterations[line_num - 1] = 0;
				line_num++;
				active_cli++;
				// Say if client should be active
				if (active_cli < MAX_CLI) {
					server_msg.be_active = 0;
				}
				else {
					server_msg.be_active = 1;
				}

				//printf("DEBUG: Msg Type sending: %d\n", server_msg.msg_type);
				//fprintf(stderr , "DEBUG: SERVER SENT BUFFER\n\n" );
				sendto( sock , (void *) &server_msg , (sizeof(server_msg)) ,
					0 , (SA *) &fsin, alen );
				break;

			// Tell client how much to make
			case 2:
				//printf("\t\tLine %d's cap: %d\n", client_msg.line_num, client_msg.capacity);
				//printf("\t\tOrder Left %d\n",order_left);
				if (client_msg.be_active) {
					curr_line = client_msg.line_num - 1;

					// If no items left, terminate client
					if (order_left <= 0) {
						server_msg.msg_type = 3;
						active_cli--;
					}
					// Make full capacity
					else if ((order_left - client_msg.capacity) > client_msg.capacity ||
						(order_left - client_msg.capacity) > 0) {
						server_msg.msg_type = 1;
						server_msg.capacity = client_msg.capacity;
						// Update Order and items
						items[curr_line] += server_msg.capacity;
						order_left = order_left - server_msg.capacity;
						//printf("DEBUG: Full capacity: %d\n", client_msg.capacity);
					
					}
					// Make partial capacity
					else {
						server_msg.msg_type = 2;
						server_msg.capacity = order_left;
						// Update order and items
						order_left = order_left - server_msg.capacity;
						items[curr_line] += server_msg.capacity;
						//printf("DEBUG: Partial capacity: %d\n", server_msg.capacity);
					}
				}
				else {
					if (active_cli == MAX_CLI) {
						server_msg.be_active = 1;
					}
					server_msg.msg_type = 2;
					server_msg.capacity = 0;
				}
				//printf("DEBUG: Msg Type sending: %d\n", server_msg.msg_type);
				//fprintf(stderr , "DEBUG: SERVER SENT BUFFER\n\n" );
				sendto( sock , (void *) &server_msg , sizeof(server_msg) ,
					0 , (SA *) &fsin, alen );
				break;

			// Client completed iteration
			case 3:
				curr_line = client_msg.line_num - 1;
				iterations[curr_line]++;
				break;
		}

		// If all lines are terminated, close socket.
		if (active_cli <= 0) {
			processing = 0;
			close(sock);
		}
	}
		printf("**** Factory History: ****\n");
		printf("Order size: %d\n\n", ordersize);
		for(ii = 0;ii < 5;ii++)
		{
		printf("Line %d's History:\n", ii + 1);
		printf("Capacity: %d\n", capacity[ii]);
		printf("Duration: %d\n", duration[ii]);
		printf("Items made: %d\n", items[ii]);
		printf("Iterations: %d\n\n", iterations[ii] - 1);
		}

}
int getCapacity()
{
	srandom(time(NULL) * random());
	return random() % (MAX_CAPACITY + 1 - MIN_CAPACITY) + MIN_CAPACITY;
}

int getDuration()
{
	srandom(time(NULL) * random());
	return random()  % (MAX_DURATION + 1 - MIN_DURATION) + MIN_DURATION;
}

int getOrdersize()
{
	srandom(time(NULL) * random());
	return random() % (MAX_ORDERSIZE + 1 - MIN_ORDERSIZE) + MIN_ORDERSIZE;
}

#endif
