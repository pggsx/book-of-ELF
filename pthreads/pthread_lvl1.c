#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<pthread.h>
#include"headers/pthread_struct.h"
/*First Attempt at working with p_threads
 * Author:Pavan Gudimetta 
 * Version 0.1
 * This application will attempt to do two calculations at the same time
 * Adopted from example in yolinux POSIX threads example
 *
 */
int main()
{

/* 
 * Initializes threads 
 * and setups the argument_t structure to be used
 *
 */		
pthread_t thread1, thread2;
argument_t *thread_args_one;
argument_t *thread_args_two;
int tret1, tret2;

thread_args_one = (argument_t*)malloc(sizeof(argument_t));
thread_args_two = (argument_t*)malloc(sizeof(argument_t));
thread_args_one->arg1 = 1;
thread_args_one->arg2 = 2;
tret1 = pthread_create(&thread1,NULL,(void*)calc,(void*)thread_args_one);
if(tret1)
{
	fprintf(stderr,"Error - pthread_create() code %d\n",tret1);
}


thread_args_two->arg1 = 3;
thread_args_two->arg2 = 5;
tret2 = pthread_create(&thread2,NULL,(void*)calc,(void*)thread_args_two);

if(tret2)
{
	fprintf(stderr,"Error - pthread_create() code %d\n",tret1);
}



	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	free(thread_args_one);
	free(thread_args_two);
 	thread_args_one = NULL;
	thread_args_two = NULL;
	exit(EXIT_SUCCESS);	
}

/* 
 * calc function
 * calculates two numbers per each thread being run
 *
 */

void* calc(void *ptr)
{
	//initialization to zero prevents garbage input
	uint8_t count = 0;
	uint8_t result = 0;
//Debug Statements
//printf("Inside of calc function + count %d\n",count);
	argument_t *args;
	args = (argument_t*)malloc(sizeof(argument_t)); 
  	args->arg1 = 0;
	args->arg2 = 0;	
	//typecasts void pointer to argument_t in order to use fields
	args = (argument_t*)ptr;
	
	/* Debugging Statements	
	printf("arguments being passed \n");
	printf("Arg 1 : %d\n",args->arg1);
	printf("Arg 2 : %d\n",args->arg2);
	*/
		
	result = args->arg1 + args->arg2;
	printf("Result: %d\n",result);
	free(args);
	args = NULL;

}
