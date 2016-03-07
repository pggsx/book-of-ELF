
 /* map.c                                                                    *
 * ------                                                                    *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This is a template for project 1.                              *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.  For documentation of standard C library           *
 * functions, see the list at:                                               *
 *   http://pubs.opengroup.org/onlinepubs/009695399/functions/contents.htm   *
* ************************************************************************* */
#include<stdlib.h> /* C Standard Library*/
#include<stdint.h> /* C Standard Int Types*/
#include<stdio.h> /* C Standard I/O*/
#include<stdbool.h> /* C Standard Bool Type*/
#include<inttypes.h> /* C Standard Int Types*/
#include"map.h" /*map.h header file*/
/* ************************************************************************* *
 * Local function declarations                                               *
 * ************************************************************************* */

/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */
 
/* ************************************************************************* *
 * build_map -- reads in files and dynamically allocates memory for the	     *
 * file being read in into an array. The array is then used to build a linked*
 * list that contains all of the areas and the building in the map_array. A  *
 * campus structure is passed in that used as a root of the linked list      *
 * in order to be referred back in the main function                         *
 * Parameters                                                                *
 *   mapfile -- file that is to be read in the function                      *
 *   areas -- the area struct that is referred within main 		     		 *
 *   buildings -- the building arrays that is to be associated with the linked
 * list.								        							 *
 *    verbose -- boolean that is used to check if the verbose flag is being  *
 * passed within main			                                     		 *
 * Returns                                                                   *
 *   Build success status. If the map is built  correctly and, successfully  *
 *    with no errors, we return the value 0. If any errors occur (such 	     *	
 *   as passing an invalid flag or passing a file that does not exist), we   *
 *   return 1 back to the calling function and stop processing               *
 *                                                                           *
 * Notes                                                                     *
 *   This function is using the linked list data structure in order to build *
 * the map that is used in later functions when performing building and area *
 *  queries                                                         	     *
 *                                                                           *
 *									    									 *
 * ************************************************************************* */




int build_map(const char *mapfile, campus_t **areas, building_t *buildings[],bool* verbose)
{
FILE *fp;
uint32_t mapsize = 0;
char *map_array = NULL;
uint8_t ii = 0;
uint8_t aa = 0;
uint8_t bb  = 0;
uint8_t tmp_cnt = 0;
	//uint8_t bldglistcnt = 0;
//bool checker = true;
//campust *head;
//*head = current;
*areas = (campus_t*)malloc(sizeof(campus_t));

	campus_t *current = NULL;
	current = *areas;
//campus_t *root == NULL;
	fp = fopen(mapfile,"rb");

	if(mapfile != NULL)
	{
	fseek(fp,0,SEEK_END);
	mapsize = ftell(fp);
	rewind(fp);	
	map_array = malloc(mapsize);
	fread(map_array,1,mapsize,fp);
	fclose(fp);
	}
	else
	{

	return -1;
	}
	if(verbose)
	{
		printf ("Opening file \"%s\"\n",mapfile);
		printf ("File contains %" PRIu32 " bytes of data\n", mapsize);
	}

while(current != NULL) 
{

		//psuedo code
		//iterate through link list
		//insert first number as area id
		//then use second number to iterate through array
		//store element iterated over into linked list
		//continue to next element
		//repeat
	for(ii = 0;ii < sizeof(map_array[0]);ii++)
		{
			current->id = map_array[ii];
			printf("ii %d\n",ii);
			ii++;
			tmp_cnt = map_array[ii];
			current->number_of_buildings = tmp_cnt;
			current->list = (building_t*)calloc(tmp_cnt,sizeof(building_t));
			printf("ii %d\n",ii);
			for(aa=ii;aa <= tmp_cnt;aa++)
			{
				current->list[aa].id = (bldg_t)map_array[aa];
				current->list[aa].area = current;
				printf("cur list id[%02X] map[%02X] index{%d] \n",current->list[aa].id,map_array[aa],aa);
				printf("cur list area[%p] map[%p] index{%d]\n",current->list[aa].area,current,aa);
			}	
		}
	current = current->next;
	printf("within while loop\n");
}		

		
			campus_t* curr = NULL;
		 	curr = *areas;
			printf("Printing out the linked list\n");
			printf("curr ptr addr %p\n",curr);
			printf("areas %p\n",&areas);
			while(curr != NULL){
   		printf("Current ID: %02X\n",(curr->id));
			printf("Building count %u\n",curr->number_of_buildings);
			for(bb = 0; bb < curr->number_of_buildings;bb++)
			{
				printf("-------\n");
				printf("%02X index[%d]\n",curr->list[bb].id,bb);
			}
				curr = curr->next;
			}
		free_areas(current);
		curr = NULL;
		return 0;
 }

/* ************************************************************************* *
 * free_areas -- traverses linked list and frees all allocated memory  within*
 * the linked list.							     							 *
 *                                                                           *
 * Parameters                                                                *
 *   root -- the root of the linked list	                                 *
 *   									     								 *
 *                                                                           *
 * Returns                                                                   *
 *   No returns 							     							 *
 *                                                                           *
 * Notes								     								 *
 * This  method is useful after all other queries or other related functions * 
 * prior to the program finishing                                            *
 *  								            							 *
 * ************************************************************************* */
void free_areas(campus_t *root)
{
	campus_t* ptr;
	ptr = root;
	while(ptr != NULL)
	{
		free(ptr);
		ptr = ptr->next;
	}
		ptr = NULL;
}
/* ************************************************************************* *
 * get_building_by_id getter method that returns building representation     *
 * of the code being passed 											     *
 *                                                                           *
 * Parameters                                                                *
 *   code --  the char code that is within the linked list                   *
 *   									    								 *
 *                                                                           *
 * Returns                                                                   *
 *   bldg_t returns building representation of code   			    	     *
 *                                                                      	 *
 * Notes								     								 *
 * This  method is useful after all other queries or other related functions * 
 * prior to the program finishing                                            *
 *  									     								 *
 * ************************************************************************* */

bldg_t get_building_by_id(const char *code)
{
	bldg_t bldg = *code;
	return bldg;


}
/* ************************************************************************* *
 * get_building_by_id getter method that returns area representation         *
 * of the code being passed													 *
 *                                                                           *
 * Parameters                                                                *
 *   code --  the char code that is within the linked list                   *
 *   									     								 *
 *                                                                           *
 * Returns                                                                   *
 *   bldg_t returns building representation of code   			     		 *
 *                                                                           *
 * Notes								     							     *
 * This  method is useful after all other queries or other related functions * 
 * prior to the program finishing                                            *
 *  									     								 *
 * ************************************************************************* */
area_t get_area_by_id(const char *code)
{
	area_t area = *code;
	return area;
}

/* ************************************************************************* *
 * building_distance -- calculates distance between two buildings using the  *
 * root of the linked list as the segway into calculating the distance	     *
 * the linked list.							     						     *
 *                                                                           *
 * Parameters                                                                *
 *   root -- the root of the linked list                                     *
 *   bldg_to the building origin					     					 *
 *   bldg_from the destination building		                             	 *
 *   									     								 *
 *                                                                           *
 * Returns                                                                   *
 *   unit32_t returns the numeric distance between both buildings	     	 *
 *                                                                           *
 * Notes								     								 *
 * This method is useful when the user is attempting to calculate the	     * 
 * distance						                     						 *
 * ************************************************************************* */

/*uint32_t building_distance (campus_t *root,bldg_t from, bldg_t to)
{ 
	uint32_t distance = 0;

	if(to.area == from.area)
	{
		distance = 5;
	}

	if(to.area > from.area)
	 {
		distance = abs(5 * (to.area - from.area));
	 }

}*/
