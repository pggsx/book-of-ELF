/* ************************************************************************* *
 * parse.c                                                                   *
 * -------                                                                   *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This code is used to parse the command-line arguments for      *
 *            CS 350 project 3.                                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.                                                    *
 * ************************************************************************* */

#include <stdio.h>              /* standard I/O */
#include <unistd.h>             /* gives us getopt() */
#include <ctype.h>              /* gives us isprint() */
#include <stdlib.h>
#include <inttypes.h>			/*Standard Int Types*/
#include <stdbool.h>			/*Boolean Library*/
#include "parse.h"              /* prototypes for exported functions */

/* ************************************************************************* *
 * Local function prototypes                                                 *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * parse_command_line -- parses the command-line arguments using getopt()    *
 *                                                                           *
 * Parameters                                                                *
 *   argc -- the number of command-line arguments                            *
 *   argv -- the array of command-line arguments (array of pointers to char) *
 *                                                                           *
 * Returns                                                                   *
 *   Parsing success status. If the command-line arguments are successfully  *
 *   parsed with no errors, we return the value 0. If any errors occur (such *
 *   as passing an invalid flag or passing a file that does not exist), we   *
 *   return 1 back to the calling function and stop processing               *
 *                                                                           *
 * Notes                                                                     *
 *   This function is designed to be extensible for multiple command-line    *
 *   options. In C, though, you can only return a single value. We get       *
 *   around this restriction by using call-by-reference parameters. For      *
 *   instance, if we want to set a boolean value, the parameter list would   *
 *   be modified as:                                                         *
 *                                                                           *
 *     parse_command_line (..., bool * boolval)                              *
 *                                                                           *
 *   Then, the function would be called from somewhere else like:            *
 *                                                                           *
 *     bool my_bool_value;                                                   *
 *     int return_code;                                                      *
 *     return_code = parse_command_line (..., &my_bool_value);               *
 * ************************************************************************* */

int
parse_command_line (int argc, char * argv[],bool *cflag,bool* oflag,const char **outputarg,const char** filename)
{
	uint32_t c;	
	while((c = getopt(argc,argv,"o:c:")) != -1 )
	{
		switch(c)

		{
			case 'o':
					*oflag = true;
					printf("inside of output mode");
					printf("generating XML file");
					*outputarg = optarg;
			break;
			case 'c':
					*cflag = true;
					printf("canonical mode\n");
					//printf("insert canonicalization implementation here");
			break;
			case '?':
			if(optopt == 'c'){
				fprintf(stderr,"Unknown option '%c' requires an argument.\n",optopt);
				exit(1);
			}
			else if(isprint(optopt))
			{
					fprintf(stderr,"Unknown option '%c'.\n",optopt);
					exit(1);
			}
			else{
				fprintf(stderr,"Unknown option character '\\x%x'.\n",optopt);
			exit(1);
			}
			default:
					return 0;
		}

	}
		
		*filename = argv[optind-1];
		if(filename == NULL)
		{
				printf("Invalid Argument, File is not being passed\n");
				exit(1);
		}
		
		if(argc == 1)
		{
		printf("No Flags Interpreted.... Do Nothing....\n");
			exit(1);
		}

    return 0;
}
