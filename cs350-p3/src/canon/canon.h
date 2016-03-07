#ifndef __CANON_HEADER__
#define __CANON_HEADER__

/*********************************************************
 * Canon.h 
 * Header file for canoncalization representation
 * Author: Pavan Gudimetta
 *
 *********************************************************/

/******************************************************
*
* function prototypes
********************************************************/
void construct_canon(const char** filename);
void traverse(assign_entry * assign);
void recur_traverse(const char * name);





#endif
