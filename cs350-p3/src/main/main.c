/* ************************************************************************* *
 * main.c                                                                    *
 * ------                                                                    *
 *  Author:   YOUR NAME HERE                                                 *
 *  Purpose:  This is a template for projects 0 and 1.                       *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.  For documentation of standard C library           *
 * functions, see the list at:                                               *
 *   http://pubs.opengroup.org/onlinepubs/009695399/functions/contents.html  *
 * ************************************************************************* */
#include <stdio.h>              /* standard I/O */
#include <stdbool.h>            /* bool types */
#include <stdint.h>             /* uint32_t, uint8_t, and similar types */
#include <stdlib.h>
#include <inttypes.h>           /* PRIu32 */
#include <math.h>

#include "../cmdline/parse.h"      /* command line parser */
#include "../logisim/logisim.h"    /* Logisim file creation utilities */
#include "../verilog/codegen.h"    /* Verilog parser */
#include "../canon/canon.h" /*Canoncalization*/

/* ************************************************************************* *
 * Local function declarations                                               *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */



/* ************************************************************************* *
 * main -- main entry point into the program.                                *
 *                                                                           *
 * Parameters                                                                *
 *   argc -- the number of command-line arguments                            *
 *   argv -- the array of command-line arguments (array of pointers to char) *
 *                                                                           *
 * Returns                                                                   *
 *   Program exit status. The standard is to return 0 for normal exit (no    *
 *   errors occurred). If something unusual happens, return some number      *
 *   other than 0, which can then indicate to the user what happened.        *
 *                                                                           *
 * Notes                                                                     *
 *   This function is similar to the "public static void Main" method used   *
 *   in Java classes.                                                        *
 * ************************************************************************* */

int
main (int argc, char * argv[])
{
	
	bool cflag;
	bool oflag;
	const char* filename;
	const char* outputarg;
	parse_command_line(argc,argv,&cflag,&oflag,&outputarg,&filename);

	// goes into the canoncalization implementation 
	if(cflag) 
	{
		construct_canon(&filename);

	}
	// goes into the XML output implementation 
	if(oflag)
	{

	}

	if(!cflag && !oflag)
			
			exit(1);
    return 0;
}
