/* ************************************************************************* *
 * main.c                                                                    *
 * ------                                                                    *
*  Author:   Pavan Gudimetta                                                  *
 *  Purpose:  This is a template for project 2.                          *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.  For documentation of standard C library           *
 * functions, see the list at:                                               *
 *   http://pubs.opengroup.org/onlinepubs/009695399/functions/contents.html  *
 * ************************************************************************* */
 
 #include <stdio.h>              /* standard I/O */
 #include <stdbool.h>            /* bool types */
 #include <stdint.h> 			/* uint32_t, uint8_t, and similar types */
 #include <inttypes.h> 			/*Integer Printing Format Types*/
 #include <stdlib.h> 			/* C standard Library*/
 #include "../cmdline/parse.h"   /* command line parser */
 #include "../interp/cpu.h" /*Structure Definitions  */

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
igned char bytes[6];*   other than 0, which can then indicate to the user what happened.        *
 *                                                                           *
 * Notes                                                                     *
 *   This function is similar to the "public static void Main" method used   *
 *   in Java classes.                                                        *
 * ************************************************************************* */

int
main (int argc, char **argv)
{
    /* Your implementation here. */
    int return_code;
	FILE *fp;
	FILE *fpsymbol;
	bool sflag = false;
	bool iflag = false;
	const char* filename;
	const char* soptarg;
	uint16_t bytes_in_file;
	uint16_t sylist_bytes_in_file;
	uint8_t *array = NULL;
	uint32_t ii = 0;

	return_code = parse_command_line (argc, argv,&filename,&sflag,&iflag,&soptarg);
    /*
    printf ("Opening file \"%s\"\n", file_name);
    printf ("File contains %" PRIu32 " bytes of data\n", bytes_in_file);

     */
/* Based on flag being passed,the interpretator will be used with or without a 
 * symbolist
 *
 */
	if(sflag)
	{
		printf("S flag accepted\n");
		printf("Insert Symbolist Implementation here\n");
		fpsymbol = fopen(soptarg,"r");
		if(soptarg != NULL)
			{
				printf("Valid SOPTARG acceptable\n");
				fseek(fpsymbol,0,SEEK_END);
				sylist_bytes_in_file = ftell(fpsymbol);
				rewind(fpsymbol);
				printf ("File contains %"PRIu32 " bytes of data\n", sylist_bytes_in_file);
				printf("Insert Symbolist Function call here\n");
			//	char buffer[50];
    			/* Check return value from fopen() here */
  			//	while (fgets (buffer, 50, fp) != NULL)
	  		//	{
		    	/* buffer contains one line of text */
		  		//}	  

			}
	fclose(fpsymbol);
	}

// Read files, dynamically allocates array based on file size and block reads
// the file into the array
	fp = fopen(filename,"rb");
	if(filename != NULL)
	{
		fseek(fp,0,SEEK_END);
		bytes_in_file = ftell(fp);
		rewind(fp);
		printf ("File contains %"PRIu32 " bytes of data\n", bytes_in_file);
		array = malloc(bytes_in_file);
		//fread(array,1,bytes_in_file,fp);
		fread(array,bytes_in_file,1,fp);
	}
	else
	{
		perror("Invalid File, Exiting now...\n");
		exit(1);


	}

	/**
	 * If iflag is true, then the interpretator will be run and depending on the sflag, the 
	 * symbol list will be passed in and used.
	 */
	if(iflag)
	{
		printf("I flag accepted\n");
		printf("Insert Interpreter Implementation here\n");
				//printf("Insert Interpreter optional argument Function call here");
				for(ii = 0;ii < bytes_in_file;ii++){	
			fetch_and_decode(array,ii);}
}

		//printf("Now Printing out array\n");
		/*By default if the interpreter flag is not passed then the disassembler is put into
		 * action and processes instruction from the hex-array 
		 *
		 * */
		if(!iflag)
		{
			fetch_and_decode(array,bytes_in_file);
		}
	//frees the array
	free(array);
	fclose(fp);
	
    printf ("Return code is %d\n", return_code);

    return 0;
}




