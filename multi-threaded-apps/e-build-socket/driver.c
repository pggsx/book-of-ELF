/***
CS361
PA4 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

#ifndef main_c
#define main_c

#include<stdio.h>
#include<stdbool.h>
#include "statemodel.h"
#include "state.h"
#include "hardware.h"

char get_input();

//Main Driver of the e-build
int main()
{
	// Have initial state print
	printf("Factory Status: ACCEPTING\n");

	// While true keep running the program 
	bool run = true;
	while(run)
	{
		// Get the user's input for e-build
		char input = get_input();

		switch(input)
		{
			case 'O':
				handle_event(ORDER_RECEIVED);
				break;
			case 'V':
				handle_event(PAYMENT_VALIDATED);
				break;
			case 'I':
				handle_event(PAYMENT_REJECTED);
				break;
			case 'F':
				handle_event(FACTORY_FAILED);
				break;
			case 'C':
				handle_event(FACTORY_SUCCESS);
				break;
			case 'R':
				handle_event(DELIVERY_SUCCESS);
				break;
			case 'L':
				handle_event(DELIVERY_FAILED);
				break;
			case 'X':
				run= false;
				break;
		}
	};

	return 0;
}

//Get Input from keyboard
char get_input()
{
	char input;
	input = getchar();	
	return input;
}

#endif
