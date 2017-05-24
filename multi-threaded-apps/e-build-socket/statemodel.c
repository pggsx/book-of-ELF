/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef statemodel_c
#define statemodel_c

#include "statemodel.h"
#include <stdlib.h>

static state_t* current_state = &accepting;

//The Event handler
void handle_event (event current_event)
{
	state_t* next_state;
	next_state = NULL;

	switch(current_event)
	{
		case ORDER_RECEIVED:
			next_state = current_state->order_received();
			break;
		case PAYMENT_VALIDATED:
			next_state = current_state->payment_validated();
			break;
		case PAYMENT_REJECTED:
			next_state = current_state->payment_rejected();
			break;
		case FACTORY_FAILED:
			next_state = current_state->factory_failed();
			break;
		case FACTORY_SUCCESS:
			next_state = current_state->factory_success();
			break;
		case DELIVERY_SUCCESS:
			next_state = current_state->delivery_success();
			break;
		case DELIVERY_FAILED:
			next_state = current_state->delivery_failed();
			break;
	}
	
	if(next_state != NULL)
	{
		current_state = next_state;
		current_state->entry_to();
	}

}
#endif
