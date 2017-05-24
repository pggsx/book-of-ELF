/***
CS361
PA5 - e-buld
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef shipping_h
#define shipping_h

#include "state.h"

//Declare all functions performed when in the closing state
static state_t* delivery_success();
static state_t* delivery_failed();
static void entry_to();
static void getAddress();

#endif
