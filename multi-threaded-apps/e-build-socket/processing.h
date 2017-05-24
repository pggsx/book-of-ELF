/***
CS361
PA5 - e-buld
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef processing_h
#define processing_h

#include "state.h"

//Declare all functions performed when in the closing state
static state_t* payment_validated();
static state_t* payment_rejected();
static void entry_to();
static void getPymentMethod();

#endif
