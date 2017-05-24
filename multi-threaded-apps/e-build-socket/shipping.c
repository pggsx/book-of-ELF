/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef shipping_c
#define shipping_c

#include<stdio.h>
#include "shipping.h"
#include "hardware.h"
#include "statemodel.h" // For the other states

//Create the object of the closing state
state_t shipping = {
	default_event_handler,	// order recieved
	default_event_handler,	// payment validated
	default_event_handler,	// payment rejected
	default_event_handler,	// factory fail
	default_event_handler,	// factory success
	delivery_success,	// delivery success
	delivery_failed,	// delivery fail
	entry_to,		// entry
	default_action		 // exit
};
state_t* delivery_success()
{
	startWarranty();
	updateStatus(DONE);
	return &accepting;
}

state_t* delivery_failed()
{
	updateStatus(LOST);
	return &accepting;
}

void entry_to()
{
	printf("Factory status: SHIPPING\n");
	getAddress();
}

void getAddress()
{
	printf("Processing delievery address. ");
	/*
	char address[100];
	scanf("%s", address);
	printf("Address: %s\n", address);
	*/
}

#endif
