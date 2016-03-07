
 /* main.c                                                                   *
 * ------                                                                    *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This is a template for project 1.                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.  For documentation of standard C library           *
 * functions, see the list at:                                               *
 *   http://pubs.opengroup.org/onlinepubs/009695399/functions/contents.htm 
* ************************************************************************* */
#include <stdlib.h> 
#include <stdio.h>             /* standard I/O */
#include <stdbool.h>            /* bool types */
#include <stdint.h>             /* uint32_t, uint8_t, and similar types */
#include <inttypes.h>
#include <string.h>
#include "../cmdline/parse.h"   /* command line parser */
#include "../campus/map.h"
#include "../campus/map-const.c"

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
main ( int argc, char **argv)
{
   const char* fname = NULL;
	campus_t *areas = NULL;
	building_t *buildings = NULL;
	bool verbose = false;
	bool m = false;
	bool d = false;
	bool o = false;
	bool b = false;
	bool a = false;
	bool q = false;
	bool h = false;
	uint32_t i = 0;
	//uint32_t aa;
	char *aoptarg;
	char *boptarg;
	char *qoptarg;
	//bldg_t bldgarg1;
	//bldg_t bldgarg2;

	//char* bldg1 = NULL;
	//char* bldg2 = NULL;
	uint32_t positioncounter = 0;
	//bldg_t location;
	area_t area;
	
   
    /* Your implementation here. */
    //int return_code;
	//int build_map_code;
    /*return_code =*/ parse_command_line (argc, argv, &fname, &verbose, &m,&d,&o,&b,&a,&q,&h,&aoptarg,&boptarg,&qoptarg);
	FILE *fp;
	
	 fp = fopen(fname,"r");
	 uint32_t bytes_in_file = 0;
	 uint8_t *array = NULL;
	 
	if(fname != NULL)
	{	
		
		fseek(fp,0,SEEK_END);
		bytes_in_file = ftell(fp);
		rewind(fp);
		
		array =  malloc(bytes_in_file);
		fread(array,1,bytes_in_file + 1,fp);	
		
		fclose(fp);
	}
	else
	{
		perror("ERROR Invalid File");
		exit(0);
	}
	if(verbose && !m)
	{	
				printf ("Opening file \"%s\"\n",fname);
				printf ("File contains %" PRIu32 " bytes of data\n", bytes_in_file);
	}
		if(!m)
			{	
				
	
						for(i = 0; i < bytes_in_file;i++)
						{
							if(d)
								{	 
								  printf("%03d ",array[i]);
										if(positioncounter == 19)
								  	{	printf("\n"); positioncounter = -1;}			 
						    	}
						    else if(o)
						        {
										printf("%03o ",array[i]);
										if(positioncounter == 21)
									{	printf("\n"); positioncounter = -1; }

								}
							else
							{
										printf("%02X ",array[i]);	
										if(positioncounter == 19)
							{			printf("\n"); positioncounter = -1; }
															
							}			
								positioncounter++;	
						}
		
										printf("\n");		
		}
		if(m)
		{	
			/*Implement Map Mode here*/
		//if(verbose)
		 build_map(fname,&areas,&buildings,&verbose);
		}
		
		if(b)
		
		{
			/*Implement Map Building Query Mode here*/
			/*printf("Searching for building code \%s\n",boptarg);	
			 printf("Printing out the linked list");
   			 printf("%02X",(areas->id));
		     printf("%d",areas->number_of_buildings);
			for(aa = 0; aa < areas->number_of_buildings;aa++)
			{
				printf("%02x",areas->list[aa].id);
			}*/
		}	
			/*location = get_building_by_id(boptarg);	
			if(BUILDINGS[location] != NULL)
			{
				printf("Building is in %s\n",BUILDINGS[location]);
			}
			else 
			{
				printf("INVALID BUILDING REQUESTED Exiting now...\n");
			}*/
		

	  	if(a)
		{
			printf("Searching for Area code %s\n",aoptarg);
			area = get_area_by_id(aoptarg);
			if(AREAS[area] != NULL)
			{
			printf("Area is %s\n",AREAS[area]);
			}
			else
			{
			printf("INVALID AREA REQUESTED Exiting now. .. \n");
			exit(0);
			}

		}



	 if(q)
		{
			//bldg1 = strtok(NULL,":");
			//bldg2 = strtok(qoptarg,":");
			//bldgarg1 = *bldg1;
			//bldgarg2 = *bldg2;
			//building_distance(bldgarg1,bldgarg2);
		}


		
	//printf ("Return code is %d\n", return_code);
    	free(array);
 	return 0; 	
}		
		
      


