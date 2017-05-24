/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef statemodel_h
#define statemodel_h 
#include <stdlib.h>
#include "state.h"
#include "hardware.h"


//Declare all of teh states used in the statemodel.
//They are all extern because they are defined (i.e.
// the memory is enumerated) elsewhere (i.e., in the .c
// files of the individual states).
extern state_t accepting;
extern state_t processing;
extern state_t manufacturing;
extern state_t shipping;



// Declare all of the functions
void 
handle_event(event current_event);

#endif
