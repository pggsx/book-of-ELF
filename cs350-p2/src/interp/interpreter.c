/* ************************************************************************* *
 * interpreter.c                                                             *
 * ------                                                                    *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This is a template for project 2.                              *
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
#include "cpu.h"			/*Structure Definition for Instructions and Symbol list*/ 
#include <string.h>
/* ************************************************************************* *
 * Local function declarations                                               *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */

/*************************************************************************** *
 * constructCPU -- construct CPU structure representation					 * 
 * 												                             *
 *                                                                           *
 * Parameters                                                                *
 *   none									 	                             *
 *                                                                           *
 * Returns                                                                   *
 *   void, N/A																 *
 * Notes                                                                     *
 *   This function can be used to setup the CPU architecuture                *
 * ************************************************************************* */

cpu_t constructCPU(){
cpu_t pep8;
pep8.nbit = false ;
pep8.zbit = false ;
pep8.cbit = false;
pep8.vbit = false ;
pep8.prog_counter = 0;
pep8.index_register = 0;
pep8.accumulator = 0;
pep8.instr_register = 0;

return pep8;
}
/*************************************************************************** *
 * execute_instruction -- executes instructions and logical operations		 * 
 * 												                             *
 *                                                                           *
 * Parameters                                                                *
 *  instr -- linked list of instructions	 	                             *
 *  pep8 -- cpu structure                                                    *
 * Returns                                                                   *
 *   void, N/A																 *
 * Notes                                                                     *
 *   This function can be used to execute instructions      		         *
 * ************************************************************************* */
 void execute_instruction(instruction_t instr, cpu_t pep8){
	printf("----------------------------------------");
	printf("Status Bits (NVZC)\t");
	printf("%d,%d,%d,%d\t\n",pep8.nbit,pep8.zbit,pep8.vbit,pep8.cbit);
	printf("Accumulator (A)\t%04X\n",pep8.accumulator);
	printf("Index Register (X)\t%04X\n",pep8.index_register);
   	printf("Program Counter (PC)\t%04X\n",pep8.prog_counter);
	printf("Instruction Register (IR)\t %04X\n",pep8.instr_register);

		if(strcmp(instr.mnemonic,"BR") == 0)
		{

		}		 
		if(strcmp(instr.mnemonic, "BRLE") == 0){
	
		}
 
		if(strcmp(instr.mnemonic, "BRLT") == 0){}
		 
 		if(strcmp(instr.mnemonic, "BREQ") == 0) {}
			
		if(strcmp(instr.mnemonic, "BRNE") == 0)
		  
		if(strcmp(instr.mnemonic, "BRGE") == 0) {}
		  
		if(strcmp(instr.mnemonic, "BRGT") == 0) {}
		  
		if(strcmp(instr.mnemonic, "NOTA") == 0) {
				pep8.accumulator = (~ pep8.accumulator + 0x01);	
		}
		  
		if(strcmp(instr.mnemonic, "NOTX") == 0) {}
		 	pep8.index_array[instr.opspec] = (~pep8.index_array[instr.opspec] + 0x01);

		if(strcmp(instr.mnemonic, "NEGA") == 0) {}
		 		pep8.accumulator = ~ pep8.accumulator; 
		if(strcmp(instr.mnemonic, "NEGX") == 0){
				pep8.index_array[instr.opspec] = ~pep8.index_array[instr.opspec];
		}  
		if(strcmp(instr.mnemonic, "ASLA") == 0) {
			pep8.accumulator = instr.opspec * 2;	
		}
		 		
		if(strcmp(instr.mnemonic, "ASLX") == 0) {	
		pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec]/2;
		
		}
		  
		if(strcmp(instr.mnemonic, "ASRA") == 0) {
				pep8.accumulator = instr.opspec/2;	
		
		}
		  
		if(strcmp(instr.mnemonic, "ASRX") == 0) {
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec]/2;
		}
		  
		if(strcmp(instr.mnemonic, "ROLA") == 0) {}
		  
		if(strcmp(instr.mnemonic, "ROLX") == 0) {}
		  
		if(strcmp(instr.mnemonic, "RORA") == 0) {}
		  
		if(strcmp(instr.mnemonic, "RORX") == 0) {}
		  
		if(strcmp(instr.mnemonic, "NOP") == 0) {
				//Do Nothing
	}
		  
		if(strcmp(instr.mnemonic, "NOP0") == 0) {
			//Do Nothing

		}
		  
		if(strcmp(instr.mnemonic, "NOP1") == 0) {
			//Do Nothing

		}
		  
		if(strcmp(instr.mnemonic, "NOP2") == 0) {
			//Do Nothing

		}
		  
		if(strcmp(instr.mnemonic, "NOP3") == 0) {
			//Do Nothing

		}
		  
		if(strcmp(instr.mnemonic, "DECI") == 0) {}
		  	//Do Nothing

		if(strcmp(instr.mnemonic, "DECO") == 0) {
		  	printf("%d",instr.opspec);
		}
		if(strcmp(instr.mnemonic, "CHARO") == 0) {
				printf("%c",instr.opspec);
		}  
		if(strcmp(instr.mnemonic, "ADDA") == 0) {
		
			pep8.accumulator = pep8.accumulator + instr.opspec;
		}	  
		if(strcmp(instr.mnemonic, "ADDX") == 0) {
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec] + instr.opspec;
		
		
		}  
		if(strcmp(instr.mnemonic, "SUBA") == 0) {
		
			pep8.accumulator = pep8.accumulator - instr.opspec;
		}
		  
		if(strcmp(instr.mnemonic, "SUBX") == 0) {
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec] - instr.opspec;
	
		}
		  
		if(strcmp(instr.mnemonic, "ANDA") == 0) {
			pep8.accumulator = pep8.accumulator & instr.opspec;
		
		
		}
		  
		if(strcmp(instr.mnemonic, "ANDX") == 0) {
		
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec] & instr.opspec;

		
		}
		  
		if(strcmp(instr.mnemonic, "ORA") == 0) {}
		  
		if(strcmp(instr.mnemonic, "ORX") == 0) {
		
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec] || instr.opspec;

		
		}
		  
		if(strcmp(instr.mnemonic,"CPA") ==  0) {}
		  
		if(strcmp(instr.mnemonic, "CPX") == 0) {
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec] - instr.opspec;

		
		}
		  
		if(strcmp(instr.mnemonic,  "LDA") == 0) {
					pep8.accumulator = instr.opspec;	
		}
		  
		if(strcmp(instr.mnemonic, "LDX") == 0) {
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec];

		}
		  
		if(strcmp(instr.mnemonic, "LDBYTEA") == 0){
				pep8.accumulator = instr.opspec << 8;
			}
		  
		if(strcmp(instr.mnemonic,"LDBYTEX") == 0){
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec]<< 8;

		
		}
		if(strcmp(instr.mnemonic, "STA") == 0){
		pep8.accumulator = instr.opspec << 8;
		}
	//	if(strcmp(instr.mnemonic, "STX") == 0){
	//	pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec];	
	//	}
		if(strcmp(instr.mnemonic, "STBYTEA") == 0)
		 		pep8.accumulator = instr.opspec << 8;	

		if(strcmp(instr.mnemonic, "STBYTEX") == 0)
		{
			pep8.index_array[instr.opspec] = pep8.index_array[instr.opspec];


		}

}
