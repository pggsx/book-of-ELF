#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<pthread.h>
#include"headers/pthread_lvl2.h"
/*
 * Pthreads Level Two 
 * Adding Mutex and semphores to this variation
 * Multi-Level Threading with added complexities
 * Author:Pavan Gudimetta
 * Version 0.1
 *
 *
 */

int main()
{
	int_t* print_case;
	print_case = (int_t*)malloc(sizeof(int_t));
	pthread_t tstack[5];
	int ii = 0;
	int thread_killer = 0;
	for(ii;ii < 5;ii++)
	{
		print_case->ii = ii;
		//printf("print case in main%d\n",print_case->ii);
		tstack[ii] = pthread_create(&tstack[ii],NULL,systemcall,(void*)print_case);
	//	pthread_join(tstack[ii],NULL);
	}
	
	free(print_case);
	print_case = NULL;
	pthread_exit(NULL);
/*	printf("Threading Complete!\n");
	system("echo Cleanup");
	system("echo removing class and object files ...");
	system("rm progs/HelloWorld.class hello hello-world");*/
	for(thread_killer;thread_killer < 5;thread_killer++)
	{
			pthread_join(tstack[thread_killer],NULL);
	}
	exit(EXIT_SUCCESS);
}

void *systemcall(void * ptr)
{
	//printf("inside of systemcall\n");
	uint8_t hello_world_case = 0;
	int_t* case_ptr;
	//case_ptr = (int_t*)malloc(sizeof(int_t));
	//printf("after struct malloc\n");	
	case_ptr =(int_t*)ptr;
	hello_world_case = (uint8_t)case_ptr->ii;
	//printf("hello_world_case %d\n",hello_world_case);
	switch(hello_world_case)
	{
		case 0:
		system("javac progs/HelloWorld.java");
		system("cd progs/");
		system("java HelloWorld");
//		printf("inside of java case\n");
		break;
		case 1:
		system("go build progs/hello-world.go");
		system("./hello-world");
//		printf("inside of go case\n");
		break;
		case 2:
		system("rustc progs/hello.rs");
		system("./hello");
//		printf("inside of rust case\n");
		break;
		case 3:
		system("whoami");
//		printf("inside of whomai\n");
		break;
		case 4:
		system("uptime");
	//	printf("inside of uptime case\n");
		break;
	}
//	free(case_ptr);

//
	case_ptr = NULL;
}
