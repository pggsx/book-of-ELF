/***
CS361
PA5 - e-buld
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef manufacturing_h
#define manufacturing_h

#include "state.h"

//Declare all functions performed when in the closing state
static state_t* factory_failed();
static state_t* factory_success();
static void entry_to();
static void exit_from();
void process_factory();
int getCapacity();
int getDuration();
int getOrdersize();

#endif
