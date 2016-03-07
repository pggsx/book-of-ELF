#ifndef __CPUPROCESSOR__
#define __CPUPROCESSOR__

/* ************************************************************************* *
 * cpu.h                                                                     *
 * -------                                                                   *
 *  Author:   Pavan Gudimetta                                                *
 *  Purpose:  Defines CPU and Instructions, Symbol List Linked List and other*
 *  related structures used throughout the Pep8 implementation	             *
 * ************************************************************************* */


/* ************************************************************************* *
 * Library includes here. If none needed, delete this comment.               *
 * ************************************************************************* */
  #include<stdint.h>
  #include<inttypes.h>
  #include<stdlib.h>
  #include<stdbool.h>

/***************************************************************************************
 * Defined structures that are going to be used in disassembler.c and interpreter.c 	*
 * as well as main.c 																	*
 * Enumerated types of LINE,ASCII,BLOCK,WORD are to be used as data types within the 	*
 * symbollist linked list implementation    											*	
 * Instruction_t Struct: Representation of a machine code instruction which contains 	*
 * a pointer to actual array of machine instructions which are represented in hex format* 
 * and the actual address of the code itself.											*
 * symtab Struct:This structure represents the structure of the symbollist linked-list	*
 * linked list implementation that is going to be used to associated particular symbols	*
 * which are associated the enumerated types defined below with the actual instructions	*
 * that are going to be passed in within the fetch_decode function of either 			*
 * interpreter.c or disassembler.c														*
 * 																						*		
 * 																						*	
 ****************************************************************************************/	

	typedef enum { LINE, ASCII, BLOCK, WORD } symtype_t;


	typedef struct instruction {
	const char* mnemonic;
	bool is_unary;
	uint16_t opspec;
	uint8_t opcode;
	bool is_accum;
	char* operand;
	const char* addrmode;
	uint8_t address;
	struct instruction_t *next;
	} instruction_t;
	
	typedef struct symtab {
   	char *label;
   	symtype_t type;
  	off_t offset;
  	size_t block_length;
   	struct symtab *next;
  	} symtab_t;
	
	typedef struct instrlist {
	instruction_t instruction;
	struct instrlist *next;	
	}instrlist_t;

	typedef struct cpu {
	bool nbit;
	bool zbit;
	bool vbit;
	bool cbit;
	uint16_t prog_counter;
	uint16_t index_register;
	uint16_t index_array[100];
	uint16_t accumulator;
	uint32_t instr_register;
	}cpu_t;	

/*******************************************************************************************
* Function Declarations
*
*********************************************************************************************/

instruction_t fetch_and_decode(uint8_t *memory,size_t index);
void disassemble_instruction(instruction_t inst,symtab_t *symbols);
void execute_instructions(instruction_t instr,cpu_t pep8);
uint8_t three_bit_register_check(uint8_t opcode);
uint8_t one_bit_register_check(uint8_t opcode);

/*******************************************************************************************
* Global Variables
*
*********************************************************************************************/
extern const char* instr_array[];
extern const char* addrmodes[];
#endif
