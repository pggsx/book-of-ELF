/* ************************************************************************* *
 * disassembler.c                                                            *
 * ------                                                                    *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  This is the the disassembler function of the Pep/8 Simulator   *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here.  For documentation of standard C library           *
 * functions, see the list at:                                               *
 *   http://pubs.opengroup.org/onlinepubs/009695399/functions/contents.html  *
 * ************************************************************************* */
 
#include <stdio.h>              /* standard I/O */
#include <stdbool.h>            /* bool types */
#include <inttypes.h> 			/*Integer Printing Format Types*/
#include <stdlib.h> 			/* C standard Library*/
#include "../interp/cpu.h"			/*Structure Definition for Instructions and Symbol list*/
#include <string.h>		/*Standard String Library*/
/* ************************************************************************* *
 * Local function declarations                                               *
 * ************************************************************************* */


/* ************************************************************************* *
 * Global variable declarations                                              *
 * ************************************************************************* */
 const char* instr_array[] = {"STOP","RETTR","MOVSPA","MOVFLGA","BR","BRLE","BRLT"
 ,"BREQ","BRNE","BRGE","BRGT","BRV","BRC","CALL","NOTA","NOTX","NEGA","NEGX","ASLA","ASLX"
 ,"ASRA","ASRX","ROLA","ROLX","RORA","RORX","NOP","NOP0","NOP1","NOP2","NOP3","DECI","DECO"
 ,"STRO","CHARI","CHARO","RET0","RET1","RET2","RET3","RET4","RET5","RET6","RET7"
 ,"ADDSP","SUBSP","ADDA","ADDX","SUBA","SUBX","ANDA","ANDX","ORA","ORX","CPA","CPX"
 ,"LDA","LDX","LDBYTEA","LDBYTEX","STA","STX","STBYTEA","STBYTEX"};
 const char* addrmodes[] = {"i","d","n","x","s","sf","sx","sxf"};

/* ************************************************************************* *
 * fetch_and_decode -- gets a individual value from the array of hex-value 	 *
 * instructions and proceeds to decode the particular instruction and		 *
 * then constructs a instruction_t object to store the instruction,its memory*
 * address, and  the hex value instruction                          		 *
 *                                                                           *
 * Parameters                                                                *
 *   *memory -- pointer to the actual value of an hex value instruction      *
 *   size  -- the size of the hex array 									 *
 *                                                                           *
 * Returns																	 *
 * 		instruction_t struct that contains the hex value instruction,		 *
 * 		the memory address of said instruction and its mnemonic 	         *
 *                                                                           *
 * Notes                                                                     *
 *   This function is similar to the "public static void Main" method used   *
 *   in Java classes.                                                        *
 * ************************************************************************* */


instruction_t fetch_and_decode (uint8_t *memory,size_t index)
{
//	printf("inside of fetch and decode\n");
	instruction_t instr;
	uint32_t ii;
	printf("-------------------------------------------------------\n");
	printf("| Address         Code        Mnemonic         Operand | \n");
	printf("-------------------------------------------------------\n");
	for(ii=0;ii < index; ){
	instr.opcode = memory[ii];
	printf("%04X\t",instr.opcode);
	
if((instr.opcode >= 0x00 && instr.opcode <= 0x03) || (instr.opcode >= 0x18 && instr.opcode  <= 23) || (instr.opcode >= 24 && instr.opcode <= 27) || (instr.opcode >= 58 && instr.opcode <= 0x5F))
	{
		instr.is_unary = true;
		ii++;
	}
	else 
	{
		instr.is_unary = false;
		instr.opspec = memory[ii+1];
		instr.opspec = instr.opspec << 8;
		instr.opspec = memory[ii+2];
	}	


 if(instr.is_unary)
 {
	switch(instr.opcode)
	{
		printf("opcode in first switch");
		printf("%04X\t",instr.opcode);
case 0x00: 
		instr.mnemonic = instr_array[0];
	break;
	case 0x01:
		instr.mnemonic = instr_array[1];
	break;
	case 0x02:
		instr.mnemonic = instr_array[2];	
	break;
	case 0x03:
		instr.mnemonic = instr_array[3];
	break;
	}
		switch(instr.opcode & 0x3F){
		printf("opcode in second switch");
		printf("%04X\t",instr.opcode);

			case 0x18:
			instr.mnemonic = instr_array[14];
 			break;
			case 0x19:
			instr.mnemonic = instr_array[15];
			break;
			case 0x1A:
			instr.mnemonic = instr_array[16];
			break;
			case 0x1B: 
			instr.mnemonic = instr_array[17];
			break;	
			case 0x1C:
			instr.mnemonic = instr_array[18];
			break;
			case 0x1D:
			instr.mnemonic = instr_array[19];
			break;
			case 0x1E:
			instr.mnemonic = instr_array[20];
			break;
			case 0x1F:
			instr.mnemonic = instr_array[21];
			break;
			case 0x20:
			instr.mnemonic = instr_array[22];
			break;
			case 0x21:
			instr.mnemonic = instr_array[23];
			break;
			case 0x22:
			instr.mnemonic = instr_array[24];
			break;
			case 0x23:
			instr.mnemonic = instr_array[25];
			break;
			case 0x24:
			instr.mnemonic = instr_array[27];
			break;
			case 0x25:
			instr.mnemonic = instr_array[28];
			break;
			case 0x26:
			instr.mnemonic = instr_array[29];
			break;
			case 0x27:
			instr.mnemonic = instr_array[30];
			break;
			case 0x28:
			instr.mnemonic = instr_array[26];
			break;
		}

	if((instr.opcode & 0xF8) ==  0x58)	
	switch(three_bit_register_check(instr.opcode)){
		printf("opcode in ret switch");
		printf("%04X\t",instr.opcode);

		case 0: instr.mnemonic  = instr_array[36];break;
		case 1: instr.mnemonic = instr_array[37];break;
		case 2: instr.mnemonic = instr_array[38]; break;
		case 3: instr.mnemonic = instr_array[39]; break;
		case 4: instr.mnemonic = instr_array[50]; break;
		case 5: instr.mnemonic = instr_array[41]; break;
		case 6: instr.mnemonic = instr_array[42]; break;
		case 7: instr.mnemonic = instr_array[43]; break;}
}

if(!instr.is_unary)
{	
	switch(instr.opcode & 0x0F){
		printf("opcode in third switch");
		printf("%04X\t",instr.opcode);

		case 0x04:
			instr.mnemonic = instr_array[4];
		break;
		case 0x06:
			instr.mnemonic = instr_array[5];
		break;
		case 0x08:
			instr.mnemonic = instr_array[6];
		break;
		case 0x0A:
			instr.mnemonic = instr_array[7];
		break;
		case 0x0C:
			instr.mnemonic = instr_array[8];
		break;
		case 0x0E:
			instr.mnemonic = instr_array[9];
		break;
		case 0x10:
			instr.mnemonic = instr_array[10];
		break;
		case 0x12:
			instr.mnemonic = instr_array[11];
		break;
		case 0x14:
			instr.mnemonic = instr_array[12];
		break;
		case 0x16:
			instr.mnemonic = instr_array[13];
		break;
		instr.addrmode = addrmodes[one_bit_register_check(instr.opcode)];
	}
	
		printf("result of anding opcode and 0x78");
		printf("%04X\n",(instr.opcode & 0x78));	
	switch(instr.opcode & 0x78){
				printf("opcode in fourth switch");
		printf("%04X\t",instr.opcode);

		case 0x30:
			instr.mnemonic = instr_array[31];
			break;
		case 0x38:
			instr.mnemonic = instr_array[32];
			break;
		case 0x40:
			instr.mnemonic = instr_array[33];
			break;
		case 0x48:
			instr.mnemonic = instr_array[34];
			break;
		case 0x50:
			printf("%04x\n", instr.opcode);
			instr.mnemonic = instr_array[35];
			break;
		case 0x60:
			instr.mnemonic = instr_array[44];
			break;
		case 0x68:
			instr.mnemonic = instr_array[45];
			break;
	}
	
	
	switch(instr.opcode & 0xF8){
		printf("opcode in fifth switch");
		printf("%04X\t",instr.opcode);

			case 0x70:
				instr.mnemonic = instr_array[46];
			break;
			case 0x78:
				instr.mnemonic = instr_array[47];
			break;
			case 0x80:
				instr.mnemonic = instr_array[48];
			break;
			case 0x88:
				instr.mnemonic = instr_array[49];
			break;
			case 0x90:
				instr.mnemonic = instr_array[50];
			break;
			case 0x98:
				instr.mnemonic = instr_array[51];
			break;
			case 0xA0:
				instr.mnemonic = instr_array[52];
				break;
			case 0xA8:
				instr.mnemonic = instr_array[53];
				break;
			case 0xB0:
				instr.mnemonic = instr_array[54];
				break;
			case 0xB8:
					instr.mnemonic = instr_array[55];
				break;
			case 0xC0:
					instr.mnemonic = instr_array[56];
				break;
			case 0xC8:
					instr.mnemonic = instr_array[57];	
				break;
			case 0xD0:
					instr.mnemonic = instr_array[58];
				break;
			case 0xD8:
					instr.mnemonic = instr_array[59];
				break;
			case 0xE0:
					instr.mnemonic = instr_array[60];	
				break;
			case 0xE8:
					instr.mnemonic = instr_array[61];
				break;
			case 0xF0:
					printf("opcode in stbyte");
					printf("%04x\n", instr.opcode);
					instr.mnemonic = instr_array[62];
				break;/**/
			case 0xF8:
					instr.mnemonic = instr_array[63];
				break;
	}
}
	if(instr.is_unary)
	{
		ii++;
	}
	else
	{	
		ii+=3;

	}
//printf("DBG PRINTING OUT INSTR\n");
//	printf("opcode");
//	printf("%04X\n",opcode);
//	printf("    ");
	//printf("mnemonic");
	printf(" %04X\n",ii);
	printf("\t\t\t%s\n",instr.mnemonic);
	printf("\t\t\t%04X",instr.opspec);
	printf("\t\t\t%s",instr.addrmode);	
//	printf("    ");
//	printf("opspec");
//	printf("%04x\n",instr.opspec);
//	printf("    ");
//	printf("  ");
//	printf("%p",instr.address);
//	printf("  ");
//	printf("SYM");
//	printf("  ");
//	printf("%c",instr.opspec);
//	printf("  ");

}
//	printf("|                                                  |\n");
//	printf("|                                                  |\n");
//	printf("---------------------------------------------------- \n");

	return instr;
	}

/* ************************************************************************* *
 * one_bit_register_check -- checks registers to see whether or not the      *
 * instruction is in the accumulator or in the index register		      	 * 
 * 												                             *
 *                                                                           *
 * Parameters                                                                *
 *   opcode -- hex-value instruction		 	                             *
 *                                                                           *
 * Returns                                                                   *
 *   uint8_t index -- determines whether or instruction stores in the        *
 *   accumulator or index register											 *
 * Notes                                                                     *
 *   This function can be in checking what the instruction's register is	 *
 * ************************************************************************* */
uint8_t one_bit_register_check(uint8_t opcode){
uint8_t index;
switch(opcode & 0x01){	
	case 0x00:
	index = 0;
	break;
	case 0x01:
	index = 1;
	break;
}
	return index;
}
/* ************************************************************************* *
 * three_bit_register_check -- checks registers to see what addressing mode  *
 * the instruction is being used in									      	 * 
 * 												                             *
 *                                                                           *
 * Parameters                                                                *
 *   opcode -- hex-value instruction		 	                             *
 *                                                                           *
 * Returns                                                                   *
 *   uint8_t index -- determines whether or instruction's addressing mode	 *
 * Notes                                                                     *
 *   This function can be in checking what the instruction's addressing mode *
 *    is																	 *
 * ************************************************************************* */
uint8_t three_bit_register_check(uint8_t opcode){
uint8_t index;
switch(opcode & 0x01){ 
	case 0x00:
	index = 0;
	break;
	case 0x01:
	index = 1;
	break;
	case 0x02:
	index = 2;
	break;
	case 0x03:
	index = 3;
	break;
	case 0x04:
	index = 4;
	break;
	case 0x05:
	index = 5;
	break;
	case 0x06:
	index = 6;
	break;
	case 0x07:
	index = 7;
	break;
}
	return index;	
	}

