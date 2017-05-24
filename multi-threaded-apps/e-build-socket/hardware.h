/***
CS361
PA3 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef hardware_h
#define hardware_h
#include <stdbool.h>

// Status enumerations
typedef enum
{
	FAIL,
	SUCCESS,
	LOST,
	DONE,
	NUMBER_OF_STATUSES
} status;

// Event enumerations
typedef enum
{
	ORDER_RECEIVED,
	PAYMENT_VALIDATED,
	PAYMENT_REJECTED,
	FACTORY_FAILED,
	FACTORY_SUCCESS,
	DELIVERY_SUCCESS,
	DELIVERY_FAILED,
	NUMBER_OF_EVENTS
} event;


// Functions for payment processing

void 
resetAttempts();

bool
invalidPymnt();

// Functions for manufacturing and shipping.
void 
chargeClient();

void 
updateStatus(status value);

void 
startWarranty();

void 
refund();

#endif
