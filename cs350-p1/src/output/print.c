/* ************************************************************************* *
 * print.c                                                                   *
 * -------                                                                   *
 *  Author:   YOUR NAME HERE                                                 *
 *  Purpose:  Header file for parse.c.                                       *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here. If none needed, delete this comment.               *
 * ************************************************************************* */
#include <stdio.h>  /*Standard I/0*/
#include <stdlib.h> /*Standard lib*/
#include <stdint.h> /*Standard int*/
#include <inttypes.h> /*Standard Int Types*/
#include <string.h> /*String lib*/
#include "../campus/map.h"          /* building/area types and constants */


/* ************************************************************************* *
 * Function prototypes here. Note that variable names are often omitted.     *
 * ************************************************************************* */
	






/* ************************************************************************* *
 * print-area - print outs a given paramatized area in a string		         * 
 * representation 				.			    							 *
 *                                                                           *
 * Parameters                                                                *
 *  area - area that is going to be printed out 			    	 		 *
 *                                                                           *
 * Returns                                                                   *
 *  No returns 								     							 *
 *              							     							 *
 *                                                                           *
 * Notes                                                                     *
 *   This function is useful for debugging during the development and testing*
 * as well as it makes printing out actual areas easier 	            	 *
 * ************************************************************************* */
	void print_area (area_t area)
	{
	   printf("%s",area);
	}

/* ************************************************************************* *
 * print-building - print outs a given paramatized building in a string      * 
 * representation 							     							 *
 *                                                                           *
 * Parameters                                                                *
 *  building - area that is going to be printed out 			    		 *
 *                                                                           *
 * Returns                                                                   *
 *  No returns 								     							 *
 *              							     							 *
 *                                                                           *
 * Notes                                                                     *
 *   This function is useful for debugging during the development and testing*
 * as well as it makes printing out actual buildings easier 	             *
 * ************************************************************************* */


	void print_building (bldg_t building)
	{
	   prinf("%s",building);
	}
/* ************************************************************************* *
 * print-distance - print outs a given paramatized distance in a string	     * 
 * representation 				.			     							 *
 *                                                                           *
 * Parameters                                                                *
 *  distance - distance that is going to be printed out 	              	 *
 *                                                                           *
 * Returns                                                                   *
 *  No returns 								     							 *
 *              							     							 *
 *                                                                           *
 * Notes                                                                     *
 *   This function is useful for debugging during the development and testing*
 * as well as it makes printing out actual distances easier 	             *
 * ************************************************************************* */
	void print_distance (uint32_t distance)
	{
	   printf("%s",distance);
	}
