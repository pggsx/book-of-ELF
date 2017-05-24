/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef factoryLines_c
#define factoryLines_c

#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h> 
#include <errno.h>

#include "mySocket.h"
#define MAXBUFLEN 2560

int main(int argc, char* argv[])
{
	// Network variables
	char *host    = "localhost";    // Default host
	char *service = "50137";	// Default service
	int s, n;                      	// socket descriptor, read count
	msgBuf msg_send;
	msgBuf msg_recv;
	//msg_send = (msgBuf*)malloc(sizeof(msgBuf));
	//msg_recv = (msgBuf*)malloc(sizeof(msgBuf));
	// Factory variables
	int line_num = 0;
	int capacity = 0;
	int duration = 0;
	int items = 0;
	int iterations = 0;
	int request = 1; // 1 is true 0 is false


	// Grab host and service if supplied
	switch (argc) 
	{
		case 1:
			break;
		case 3:
			service = argv[2];
			/* FALL THROUGH */
		case 2:
			host = argv[1];
			break;
		default:
			// Print how to use the client
			fprintf(stderr, "usage: %s [host [port]]\n" , argv[0] );
			exit(1);
	}

	printf("DEBUG: Host:Service = %s:%s\n", host, service);
	s = clientUDPsock(host, service); // Create socket
	/* socket will always send to host:service */
	/* Therefore, use  in sendto( .... , NULL , 0) */

	// Setup nanosleep 
	struct timespec t;
	t.tv_sec = 0;
	t.tv_nsec = duration * 1000000;

	// Request from server to make items
	while(request) {
		// If the client has its line number, ask for a job
		if (line_num != 0) {
			msg_send.msg_type = 2;
		}
		else
		{
			msg_send.be_active = 0;
 			msg_send.msg_type = 1;
		}
		msg_send.capacity = capacity;
		msg_send.line_num = line_num;

		// Send request message (must send the \0 at end of msg, too)
		//printf("DEBUG: Msg_type sending: %d\n", msg_send.msg_type);
		sendto(s, (void *) &msg_send, sizeof(msg_send) , NULL , 0);

		// Get the message, if error report it
		n = recvfrom(s, (void*) &msg_recv , sizeof(msg_recv) , NULL , 0 );
		if ( n <= 0 )
			err_sys("Failed to get the daytime from the server\n");
		//printf("DEBUG: be_active: %d\n", msg_recv.be_active);
		if (msg_recv.be_active || msg_recv.msg_type == 0) {
			// Process message
			//printf("Msg_type recieving: %d\n", msg_recv.msg_type);
			switch (msg_recv.msg_type) {
				// Process info
				nanosleep(&t, NULL);
				case 0:
					//printf("DEBUG:\t\t\tInitial duration: %d\n", msg_send.duration);
					msg_send.msg_type = 3;
					line_num = msg_recv.line_num;
					capacity = msg_recv.capacity;
					duration = msg_recv.duration;
					break;
				// Make full capacity
				case 1:
					//printf("DEBUG: Full capacity: %d\n", capacity);
					msg_send.msg_type = 3;
					msg_send.line_num = line_num;
					msg_send.capacity = capacity;
					msg_send.duration = duration;
					msg_send.be_active = 1;
					// Send response message (must send the \0 at end of msg, too)
					sendto(s, (void *) &msg_send, sizeof(msg_send) , NULL , 0);
					items += msg_send.capacity;
					iterations++;
					break;
				// Make partial capacity
				case 2:
					//printf("DEBUG: Partial capacity %d\n", msg_recv.capacity);
					msg_send.msg_type = 3;
					msg_send.line_num = line_num;
					msg_send.capacity = msg_recv.capacity;
					msg_send.duration = duration;
					msg_send.be_active = 1;
					// Send response message (must send the \0 at end of msg, too)
					sendto(s, (void *) &msg_send, sizeof(msg_send) , NULL , 0);
					items += msg_send.capacity;
					if (msg_send.capacity > 0)
						iterations++;
					break;
				// Terminate client
				case 3:
					//printf("DEBUG: I'm terminating\n");
					request = 0;
					break;
				default:
					break;
			}
			//printf("DEBUG: Capacity: %d; Msg Capacity: %d\n", capacity, msg_send.capacity);
		}
	}
	// Print line info
	printf("\n\n*** Line %d's History: ***\n", line_num);
	printf("Capacity: %d\n", capacity);
	printf("Duration: %d\n", duration);
	printf("Items made: %d\n", items);
	printf("Iterations: %d\n", iterations);
	printf("Line %d has completed its portion of the order\n\n", line_num);

	return 0;
}

#endif
