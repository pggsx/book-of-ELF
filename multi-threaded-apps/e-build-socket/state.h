/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef state_h
#define state_h

//Add an alias for a type to the global namespace
typedef struct state state_t; 

//Add an alias for event handlers
typedef state_t* event_handler(void);

//Add an alias for actions
typedef	void action(void);

//Define the format for a state struct
struct state
{
	event_handler* order_received;
	event_handler* payment_validated;
	event_handler* payment_rejected;
	event_handler* factory_failed;
	event_handler* factory_success;
	event_handler* delivery_success;
	event_handler* delivery_failed;
	action*	entry_to;
	action*	exit_from;
};




//Declare variables to hold pointers to the default event handler and
// the default action; They are extern because they are used in each 
// of the individual state files but defined in state.c

extern state_t* default_event_handler();
extern void default_action();

#endif
