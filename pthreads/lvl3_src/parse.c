/*
* Author: Pavan Gudimetta
* File Name: parse.c
* Date: Thu Jul 30 16:17:27 EDT 2015  
* 
*
*
*
*
**/
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<unistd.h>
#include<ctype.h>
#include<stdbool.h>
#include"parse.h"
//global variables


//function prototypes




uint8_t parse_command_line(int argc,char **argv,bool *vflag,
				bool *oflag,bool *mflag, bool *pflag, bool *hflag,char **output_file)
{
	uint8_t c;
	while((c = getopt (argc,argv,"vmpho:")) != -1)
	{
		switch(c)
		{	
			case 'v':
				*vflag = true;
			break;
			case 'm':
				*mflag = true;
			break;
			case 'o':
				*oflag = true;
				*output_file = optarg;
			break;
			case 'p':
				*pflag = true;
				*num = optarg;
			break;
			case 'h':
				*hflag = true;
			break;
			
			case '?':
			if(optopt == 'c')
				fprintf(stderr,"Option -%c requires an argument.\n",	optopt);
			else if(isprint	(optopt))
					fprintf(stderr,"Unknown option '%-c'.\n",optopt);
			else
				fprintf(stderr,"Unknown option character '\\x%x.\n",optopt);
			break;
		}


	}
}


