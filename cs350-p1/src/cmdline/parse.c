/* ************************************************************************* *
 * parse.c                                                                   *
 * -------                                                                   *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This code is used to parse the command-line arguments for      *
 *            CS 350 project 1.                                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.                                                    *
 * ************************************************************************* */

#include <stdio.h>              /* standard I/O */
#include <unistd.h>             /* declares getopt() */
#include <ctype.h>              /* declares isprint() */
#include <stdint.h>		/* declares standard integer */
#include <stdlib.h>
#include <stdbool.h>
#include "parse.h"              /* prototypes for exported functions */

/* ************************************************************************* *
 * Local function prototypes                                                 *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */
//char *filename;
 
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
parse_command_line (int argc, char **argv,const char** fname, bool* verbose, bool*m,bool*d,bool*o,bool*b,bool*a,bool*q,bool*h,char **aoptarg,char **boptarg, char **qoptarg)
{
    uint32_t vflag = 0;
    uint32_t dflag = 0;
    uint32_t oflag = 0;
    uint32_t mflag = 0;
    uint32_t bflag = 0;
    uint32_t aflag = 0;
    uint32_t qflag = 0;
    uint32_t hflag = 0;
    //char *cvalue = NULL;
    //uint32_t index;
    uint32_t c;
    
    
    opterr = 0;
    while ((c = getopt (argc, argv, "mvdohb:a:q:")) != -1)
    {
    switch (c)
      {

      case 'v':
			vflag = 1;
			break;
			
      case 'd':
			dflag = 1;    
			break;
			
      case 'o':
			oflag = 1;
			break;
			
        case 'm':
			mflag = 1;
			break;
        
        case 'b':
			bflag = 1;
			*boptarg = optarg;	
		break;
        
		case 'a':
			aflag = 1;
			*aoptarg = optarg;
			break;
        
        case 'q':
			qflag =1;
			*boptarg = optarg;
			 break;
        
		case 'h':
			hflag = 1;
			break;
	
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
		return 0;
      }
	  
  }		
	  	*fname = argv[optind];
  		if(fname == NULL)
		{
			printf("Invalid Argument,File not being passed \n");
			exit(1);
		}
  
  /* Use these print statements in this order based on the flags processed */
  
		  if(vflag == 1)
		    {
				*verbose = true;
				printf("Running in verbose mode\n");
				if(mflag == 0)
				{
				  printf ("Running in numeric mode\n");
				    if(dflag == 0 && oflag == 0)
					{
					printf ("Output will be in hexidecimal format\n");
					*o = false;
					*d = false;				
					}
					if(dflag == 1 && oflag == 1)
					{
						printf("ERROR User must select either octal or decimal format\n");
						printf("Exiting Now..\n");
						exit(0);
					}
				
				     if(dflag == 1)
				       {
					printf("Output will be in decimal format\n");
					*d = true;
				       }
		  
					if(oflag == 1)
					{ 
				             *o = true;
					     
					     printf ("Output will be in octal format\n");
					}
				}
				
			  	if(mflag == 1)
				{	
					*m = true;
					//printf("Running in map mode\n"); 
				}

				if(aflag == 1)
				{
					*a = true;
									//printf("Entering query map-area mode\n");
				}

				if(bflag == 1)
				{	
					*b = true;
				
					//printf("Entering Building query map mode\n");
				
				}
				
				if(qflag == 1)
				{
					*q = true;
					*qoptarg = optarg;				 
					//printf("Entering query map bldg:bldg mode\n");
				
				}
			if(mflag == 1 && bflag == 0 && qflag == 0)
			{
				printf("Invalid argument being passed \n");
				printf("User must input additional arguments\n");
				exit(0);
			}


		}
			if(hflag == 1 && mflag == 0 && vflag == 0)
			{
				 printf("Usage: hexdumper [-v] filename \n");
				 printf("hexdumper [-v] -d filename\n");
				 printf("hexdumper [-v] -o filename\n");
				 printf("hexdumper [-v] -m [-b bldg | -a area | -q bldg:bldg] filename\n");
				 printf("-v            Run the program in verbose mode, printing extra output\n");
				 printf("-d            Print the input data as decimal format\n");
				 printf("-o            Print the input data as octal format \n");
				 printf("-m            Switch to map mode and execute a query of the campus \n");
				 printf("-b bldg       Query the map about a particular building \n");
				 printf("-a area       Query the map about a particular area of campus \n");
				 printf("-q bldg:bldg  Query the map about the distance between two buildings \n");
				 printf("-h            Print this help message and quit \n");
				 exit(0);
			}    
			

		if(dflag == 1 && oflag ==1)
		{
			printf("ERROR Invalid Input user must enter either Decimal or Octal Mode\n");
			exit(0);
		}

			if(vflag == 0)
			{
					
				 if(dflag == 0 && oflag == 0 && mflag == 0)
					{
					*o = false;
					*d = false;
					//*verbose = true;				
					}

				 if(dflag == 1)
				  {
				    *d = true;
				  }
		  
				if(oflag == 1)
				{ 
					*o = true;
				}
			
			  	if(mflag == 1)
				{	
					*m = true;
				}
			

				if(aflag == 1)
				{
					*a = true;
					*aoptarg = optarg;
				}

				if(bflag == 1)
				{	
					*b = true;
				
				
				}
				
				if(qflag == 1)
				{
					*q = true;
					*qoptarg = optarg;				 
					printf("Entering query map bldg:bldg mode\n");
				
				}


		if((mflag == 1 && bflag == 0) || (mflag ==1 && aflag == 0) || (mflag == 1 && qflag == 0))
			{
				printf("Invalid argument being passed \n");
				printf("User must input additional arguments\n");
				exit(0);
			}
		}


			if(mflag == 0)
			{
				if(bflag == 1 || aflag == 1 || qflag == 1) 
				{ 
				   printf("invalid argument being passed user must be in map mode \n"); 
				   bflag = 0;
				   aflag = 0;
				   qflag = 0;
				   exit(0);
				}
					
			}
			
			if(mflag == 1)
			{
			   if(oflag == 1 || dflag == 1)
				{
				  printf("invalid argument being passed user must be in numeric mode \n");
				  oflag = 0;
				  dflag = 0;
				  exit(0);
		   
				}

			}







  	return 0;
}


