/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef processing_c
#define processing_c

#include<stdio.h>
#include <stdlib.h>
#include "processing.h"
#include "hardware.h"
#include "statemodel.h" // For the other states

//Create the object of the processing state
state_t processing = {
	default_event_handler,	// order recieved
	payment_validated,	// payment validated
	payment_rejected,	// payment rejected
	default_event_handler,	// factory fail
	default_event_handler,	// factory success
	default_event_handler,	// delivery success
	default_event_handler,	// delivery fail
	entry_to,		// entry
	default_action		 // exit
};

state_t* payment_validated()
{
	printf("Card was validated.\n");
	return &manufacturing;
}

state_t* payment_rejected()
{
	printf("Card was rejected.\n");
	if (invalidPymnt())
	{
		return &accepting;
	}
	else
	{
		return &processing;
	}
	
}

void entry_to()
{
	printf("Factory status: PROCESSING\n");
	getPymentMethod();
}

void getPymentMethod()
{
	printf("Processing payment...\n");
	/*
	char cardNum[16];
	scanf("%s", cardNum);
	printf("Credit card #%s\n", cardNum);
	*/
}

#endif
