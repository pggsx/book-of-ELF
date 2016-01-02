/*
* Author: Pavan Gudimetta
* File Name: pthread_lvl3.c
* Date: Thu Jul 30 16:01:22 EDT 2015  
* 
* Pthread Level 3
* Using different types of multi-threaded implementations
* Primarly, OpenMP v POSIX threading
*
**/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<inttypes.h>
#include<stdbool.h>
#include<pthread.h>
#include<omp.h>
#include"lvl3_src/parse.h"
//global variables


//function prototypes




int main(int argc, char **argv)
{
	uint8_t cmd_line = 0;
	bool vflag;
	bool oflag;
	bool mflag;
	bool pflag;
	bool hflag;
	char* output_file;
	uint8_t num;
	uint8_t ii;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	cmd_line = parse_command_line(argc,argv,&vflag,&oflag,
																&mflag,&pflag,&num,&hflag,&output_file);

	if(vflag)
	{	
		printf("Running in Verbose Mode");
	}
	if(oflag)
	{
		if(output_file != NULL)
		{
			//fwrite to file
		}
		fprintf(stderr,"File I/O Error");

	}
	if(mflag)
	{
		//insert OpenMP implementation here
	}	
	if(pflag)
	{
		if(num >= 0)
		{
			thread_t[num] threads;
			for(ii = 0;ii < num;ii++)
			{
				thread_create(&thread[ii],func,(void*)1);
			}
		}
		else
		{
			perror("Error Status: ");
		}
		//insert pthread implementation
	}
	if(hflag)
	{
		printf("Multi-Thread Simulator\n");
		printf("usage: ./threadsim [-o] file "); 
		printf("-v Verbose Mode\n");
		printf("-m[int] Use OpenMP for multi-threading based on n threads");
		printf("-p[int] Use POSIX pthreads for multi-threading based on n threads");
		printf("-o[FILE] writes threadsim output to file");
		printf("-h Prints out Help Menu");
		exit(0);
	}

	return cmd_line;
}

/* 
 * Function that does something 
 *
 */
void* func(void* _arg)
{




}


