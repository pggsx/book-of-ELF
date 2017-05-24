/***
CS361
PA4 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef hardware_c 
#define hardware_c 

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include "hardware.h"

// Limit of payment validation attempts
static const uint32_t LIMIT = 2;
// Number of validation attempts
static uint32_t attempts = 0;

void 
resetAttempts()
{
	//printf("DEBUG: Attempts: %i\n", attempts);
	attempts = 0;
}

bool
invalidPymnt()
{
	//printf("DEBUG: Attempts: %i\n", attempts);
	// If attempts >= LIMIT return true to change to accepting state
	if (attempts >= LIMIT)
	{
		return true;
	}
	else
	{
		// Increment attempts
		attempts++;
		return false;
	}
}

void 
chargeClient()
{
	printf("You have now been charged for your order.\n");
}

void 
updateStatus(status value)
{
		switch(value)
	{
		case FAIL:
			printf("The factory had a mishap, your order has been canceled.\n");
			break;
		case SUCCESS:
			printf("The factory has finished producing your order.\n");
			break;
		case LOST:
			printf("Your order has been lost.\n");
			refund();
			break;
		case DONE:
			printf("Your order is complete.\n");
			break;
	}
}

void 
startWarranty()
{
	printf("Thank you for placing your order with us!"
		" Your order warrenty has now begun.\n");	
}

void
refund()
{
	printf("Your order has been refunded. Sorry for the inconvenience.\n");
}
#endif
