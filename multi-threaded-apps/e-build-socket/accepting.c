/***
CS361
PA4 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef accepting_c
#define accepting_c

#include<stdio.h>
#include "accepting.h"
#include "hardware.h"
#include "statemodel.h" // For the other states

//Create the object of the closing state
state_t accepting = {
	order_received,		// order recieved
	default_event_handler,	// payment validated
	default_event_handler,	// payment rejected
	default_event_handler,	// factory fail
	default_event_handler,	// factory success
	default_event_handler,	// delivery success
	default_event_handler,	// delivery fail
	entry_to,		// entry
	default_action		 // exit
};
state_t* order_received()
{
	resetAttempts();
	return &processing;
}

void entry_to()
{
	printf("Factory status: ACCEPTING\n");
}

#endif
