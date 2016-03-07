
/******************************************************************************
 * Canon.c 
 *--------
 * Author: Pavan Gudimetta
 * Purpose: Interprets AST and show canonicalization of Verilog file
 *
 *
 * ****************************************************************************/
/* parse_file returns the AST from parsing mycirc.v */

#include<stdio.h> 
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<math.h>
#include"../logisim/logisim.h"
#include"../verilog/codegen.h"
#include"canon.h"

ast_t * ast;
module_t * module;
/******************************************************************************
 *  Construct Canon
 * constructs canonicalization of AST and prints out basic and expanded version 
of circuit based off a verilog file. It then builds the AST and traverses the tree
 * While the tree is being traversed, it will then print out the basic version 
 * of the verilog file based on its assignment value of INPUT, OUTPUT or WIRE.
 * @params filename - name of verilog files
 *
 * ****************************************************************************/
void construct_canon(const char** filename)
{
	
	//printf("inside of construct_canon\n");
	const char* verilog_file = *filename;
	ast = parse_file (verilog_file);
	module = ast->modules;
	symtab_entry * symbol = NULL;
	symbol = module->symtab;

	// IN ORDER TRAVERSAL OF BINARY TREE
		for (symbol = module->symtab; symbol != NULL; symbol = symbol->next)
		{
		
			printf("%s",symbol->name);
			//printf("\n");
			switch(symbol->type)
			{
				case 20:
					printf(" [INPUT] \n");
				//	printf("\n");
				break;
				case 21:
					printf(" [OUTPUT] = ");
					traverse(symbol->assign);
					printf("\t>>Expanded: ");
					//recur_traverse(symbol->name);
					printf("\n");
		
				break;
				case 22:
					printf(" [WIRE] = ");
					traverse(symbol->assign);
					printf("\n");
					printf("\t>>Expanded: ");
					//recur_traverse(symbol->name);
					printf("\n");	
					break;
			}


		}

}
/******************************************************************************
 * Traverse- 
 * traverses and performs an in-order tree traversal AST and prints outs the 
 * binary and unary operations within tree
 * based on type Depending on what type of operation is being conducted, 
 * it will print out the binary and unary operands and their respective operators 
 * in order
 *
 * ****************************************************************************/
void traverse(assign_entry * assign)
{
binary_op *bop = NULL;
unary_op *uop = NULL;

	if(assign->type == 12){
 	uop = assign->eval.uop;
		if((uop->op) == 0)
				printf("%s%s%s","(~",assign->eval.uop->rhs.name,")\n");
		else if ((uop->op) >= 1){
				printf("invalid equation\n");
				return;
		}
	}
	if(assign->type == 13)
	{	
			bop = assign->eval.bop;
			if ((bop->op) == 1)
			{	
				if(bop->rhs.bop->op > 0 && bop->lhs.bop->op > 0)
				{
					printf("%s%s%s%s%s"," (",bop->lhs.name,")||(",bop->rhs.name,")\n");
				}
				if(bop->rhs.bop->op == 0)		
				{
					printf("%s%s%s%s%s%s%s"," (",bop->lhs.name,")||","(~(",bop->rhs.uop->rhs.name,")",")");
				}
				if(bop->lhs.bop->op == 0)		
				{
					printf("%s%s%s%s%s%s"," (~(",bop->lhs.name,")||","(",bop->rhs.uop->rhs.name,")");
				}
			}
		// 	printf("\n");	
			if ((bop->op) == 2)
			{	
				if(bop->rhs.bop->op > 0 && bop->lhs.bop->op > 0)
				{
					printf("%s%s%s%s%s", " (",bop->lhs.name,")^(",bop->rhs.name,")");
				}

				if(bop->rhs.bop->op == 0)
				{			
					printf("%s%s%s%s%s%s%s"," (",bop->lhs.name,")&","(~(",bop->rhs.uop->rhs.name,")",")");	
				}
				if(bop->lhs.bop->op == 0)		
				{
					printf("%s%s%s%s%s%s"," (~(",bop->lhs.name,")||","(",bop->rhs.uop->rhs.name,")");
				}
			}

			//	printf("\n");
			if ((bop->op) == 3)
			{	if(bop->rhs.bop->op > 0 && bop->lhs.bop->op > 0)
				{
					printf("%s%s%s%s%s", " (",bop->lhs.name,")^(",bop->rhs.name,")");
				}
				if(bop->rhs.bop->op == 0)
				{
					printf("%s%s%s%s%s%s%s"," (",bop->lhs.name,")^","(~(",bop->rhs.uop->rhs.name,")",")");	
				}
				if(bop->lhs.bop->op == 0)		
				{
					printf("%s%s%s%s%s%s"," (~(",bop->lhs.name,")||","(",bop->rhs.uop->rhs.name,")");
				}
			}

			
			//	printf("\n");
	}
}
/******************************************************************************
 * Recursively traverses the AST and prints out the expanded version of the
 * basic circuit representation depending on whether or not the symbol of the 
 * name being
 * found is an identifier. If its an identifier, then it will recursively go 
 * through the tree
 * until the assignment is NULL (ie its an input) and the symbol name and the 
 * name being passed in are the same
 *
 *
 * ****************************************************************************/
void recur_traverse(const char * name)
{
	symtab_entry * symbol = NULL;
	symbol = module->symtab;

	
	
		if(symbol->assign == NULL && !strcmp(symbol->name, name))
		{
			printf("%s(",symbol->name);
		}
		else
		{
			for (symbol = module->symtab;symbol != NULL; symbol = symbol->next)
			{
				if(symbol->assign->type == 11)
				{
					recur_traverse(symbol->name);
				}
				else
					{
						if(symbol->assign->type == 12)
						{
							if(symbol->assign->eval.uop->rtype == 11)
							{
								printf("~(");
								recur_traverse(symbol->assign->eval.uop->rhs.uop->rhs.name);
								printf(")");
							}
							else
							{
								recur_traverse(symbol->assign->eval.uop->rhs.uop->rhs.name);
							}
						}

						if(symbol->assign->type == 13)
						{
							if(symbol->assign->eval.bop->ltype == 11)
							{
								recur_traverse(symbol->assign->eval.bop->lhs.name);
							}
							if(symbol->assign->eval.bop->rtype == 11)
							{
								recur_traverse(symbol->assign->eval.bop->rhs.name);
							}	
						}
					}
			}
		}


}
