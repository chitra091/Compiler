%{
#include "FP.h"
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
extern FILE* yyin;
extern char* yytext;
extern int yy_flex_debug;
int symbol_index=0;
FILE *fp;
node *rootnode = NULL;
int print_index=0;
int memory_index=0;
int register_index=0;
int get_mem_index();
int get_register_index();
int codegen(node *p);
%}

%union {char* string_val; node *nodetype;}         /* Yacc definitions */
%start program
%token exit_command
%token <string_val> constant
%token <string_val> function
%token <string_val> mainkey
%token <string_val> readkey
%token <string_val> printkey
%token <string_val> returnkey
%token <string_val> ifkey
%token <string_val> thenkey
%token <string_val> elsekey
%token <string_val> loop
%token <string_val> whilekey
%token <string_val> equal
%token <string_val> predefined
%token <string_val> comparison_op
%token <string_val> open_spl_char
%token <string_val> close_spl_char
%token <string_val> boolean
%token <string_val> integer_value
%token <string_val> float_value
%token <string_val> identifier
%token <string_val> string
%type <string_val> number
%type <nodetype> program constantdefs constantdef scalar_param functiondefs functiondef args statements statement assgn_stmt read_stmt idplus
%type <nodetype> print_stmt print_param_plus print_param parameter function_call function_name parameters if_stmt loop_stmt while_stmt expr co_op
%%

/* descriptions of expected inputs     corresponding actions (in C) */

program				: constant constantdefs function functiondefs mainkey statements			{$$=create_node("program");
															 $$->childnode=create_node($1);
															 $$->childnode->siblings=create_node1($2);
															 $$->childnode->siblings->siblings=create_node($3);
															 $$->childnode->siblings->siblings->siblings=create_node1($4);
															 $$->childnode->siblings->siblings->siblings->siblings=create_node($5);
															 $$->childnode->siblings->siblings->siblings->siblings->siblings=create_node1($6);
															 rootnode=$$;
															 printf("PARSE TREE\n");
															 in_order_traversal(rootnode,print_index);
															 }
				;
constantdefs			: constantdef constantdefs								{$$=create_node("constantdefs");
															 $$->childnode=create_node1($1);
															 $$->childnode->siblings=create_node1($2);}
				| 											{$$=NULL;}
				;
constantdef			: open_spl_char identifier scalar_param close_spl_char					{$$=create_node("constantdef");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node1($3);
															 create_symbol_node($2,$3->childnode->val,"string",999);}
				;
scalar_param			: number										{$$=create_node("scalar_param");
															 $$->childnode=create_node($1);}
				| boolean										{$$=create_node("scalar_param");
															 $$->childnode=create_node($1);}
				| string										{$$=create_node("scalar_param");
															 $$->childnode=create_node($1);}
				;
number				: integer_value										{$$=$1;}
				| float_value										{$$=$1;}
				;
functiondefs			: functiondef functiondefs								{$$=create_node("functiondefs");
															 $$->childnode=create_node1($1);
															 $$->childnode->siblings=($2);}
				| 											{$$=NULL;}
				;
functiondef			: open_spl_char function_name args returnkey identifier statements close_spl_char	{$$=create_node("functiondef");
															 $$->childnode=create_node1($2);
															 $$->childnode->siblings=create_node1($3);
															 $$->childnode->siblings->siblings=create_node($4);
															 $$->childnode->siblings->siblings->siblings=create_node($5);
															 $$->childnode->siblings->siblings->siblings->siblings=create_node1($6);
															 create_symbol_node($5,NULL,"string",999);}
				;
args				: identifier args									{$$=create_node("args");
															 $$->childnode=create_node($1);
															 $$->childnode->siblings=create_node1($2);
															 create_symbol_node($1,NULL,"string",999);}
				| identifier										{$$=create_node("args");
															 $$->childnode=create_node($1);
															 create_symbol_node($1,NULL,"string",999);}
				;
statements			: statement statements									{$$=create_node("statements");
															 $$->childnode=create_node1($1);
															 $$->childnode->siblings=create_node1($2);}
				|											{$$=NULL;}									
				;
statement			: assgn_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				| read_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				| print_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				| if_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				| loop_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				| while_stmt										{$$=create_node("statement");
															 $$->childnode=create_node1($1);}
				;
assgn_stmt			: open_spl_char equal identifier parameter close_spl_char				{$$=create_node("assgn_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node($3);
															 $$->childnode->siblings->siblings=create_node1($4);
															 create_symbol_node($3,NULL,"string",999);}
				;
read_stmt			: open_spl_char readkey idplus close_spl_char						{$$=create_node("read_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node1($3);}
				;
idplus				: identifier idplus									{$$=create_node("idplus");
															 $$->childnode=create_node($1);
															 $$->siblings=create_node1($2);
															 create_symbol_node($1,NULL,"string",999);}
				| identifier										{$$=create_node("idplus");
															 $$->childnode=create_node($1);
															 create_symbol_node($1,NULL,"string",999);}
				;
print_stmt			: open_spl_char printkey print_param_plus close_spl_char				{$$=create_node("print_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node1($3);}
				;
print_param_plus		: print_param print_param_plus								{$$=create_node("print_param_plus");
															 $$->childnode=create_node1($1);
															 $$->siblings=create_node1($2);}
				| print_param										{$$=create_node("print_param_plus");
															 $$->childnode=create_node1($1);}
				;
print_param			: identifier 										{$$=create_node("print_param");
															 $$->childnode=create_node($1);
															 create_symbol_node($1,NULL,"string",999);}
				| scalar_param 										{$$=create_node("print_param");
															 $$->childnode=create_node1($1);}
				;
parameter			: function_call										{$$=create_node("paramter");
															 $$->childnode=create_node1($1);}
				| identifier										{$$=create_node("parameter");
															 $$->childnode=create_node($1);
															 create_symbol_node($1,NULL,"string",999);}
				| number										{$$=create_node("parameter");
															 $$->childnode=create_node($1);}
				;
function_call			: open_spl_char function_name parameters close_spl_char					{$$=create_node("function_call");
															 $$->childnode=create_node1($2);
															 $$->childnode->siblings=create_node1($3);}
				;
function_name			: identifier										{$$=create_node("funtion_name");
															 $$->childnode=create_node($1);
															 create_symbol_node($1,NULL,"string",999);}
				| predefined										{$$=create_node("funtion_name");
															 $$->childnode=create_node($1);}
				;
parameters			: parameter parameters									{$$=create_node("parameters");
															 $$->childnode=create_node1($1);
															 $$->childnode->siblings=create_node1($2);}
				|										 	{$$=NULL;}
				;
if_stmt				: open_spl_char ifkey expr thenkey statements elsekey statements close_spl_char		{$$=create_node("if_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node1($3);
															 $$->childnode->siblings->siblings=create_node($4);
															 $$->childnode->siblings->siblings->siblings=create_node1($5);
															 $$->childnode->siblings->siblings->siblings->siblings=create_node($6);
															 $$->childnode->siblings->siblings->siblings->siblings->siblings=create_node1($7);}
				;
loop_stmt			: open_spl_char loop identifier statements close_spl_char				{$$=create_node("loop_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node($3);
															 $$->childnode->siblings->siblings=create_node1($4);
															 create_symbol_node($3,NULL,"string",999);}
				;
while_stmt			: open_spl_char whilekey expr statements close_spl_char					{$$=create_node("while_stmt");
															 $$->childnode=create_node($2);
															 $$->childnode->siblings=create_node1($3);
															 $$->childnode->siblings->siblings=create_node1($4);}
				;
expr				: open_spl_char co_op parameter parameter close_spl_char				{$$=create_node("expr");
															 $$->childnode=create_node1($2);
															 $$->childnode->siblings=create_node1($3);
															 $$->childnode->siblings->siblings=create_node1($4);}
				| open_spl_char boolean close_spl_char							{$$=create_node("expr");
															 $$->childnode=create_node($2);}
				;
co_op				: comparison_op										{$$=create_node("co_op");
															 $$->childnode=create_node($1);}
				;	
%%                     /* C code */

node *create_node(char *nodevalue){
	node *new_temp_node = (node*)malloc(sizeof(node));
	new_temp_node->val=nodevalue;
	new_temp_node->childnode=NULL;
	new_temp_node->siblings=NULL;
	return new_temp_node;
}

node *create_node1(node *tempnode){
	node *new_temp_node = (node*)malloc(sizeof(node));
	new_temp_node=tempnode;
	return new_temp_node;
}

void in_order_traversal(node *tempnode, int print_index){
	if(tempnode){
		printf("%*s" "%s\n", 2*print_index, " ", tempnode->val);
		if(tempnode->childnode!=NULL){
			print_index++;
			in_order_traversal(tempnode->childnode,print_index);
		}
		in_order_traversal(tempnode->siblings,print_index);
	}
}

void print_symbol_table(){
	int i=0;
	while(i<symbol_index){
		printf("name: %s\n",symbol_table[i].name);
		printf("value: %s\n",symbol_table[i].value);
		printf("type: %s\n",symbol_table[i].type);
		printf("address: %d\n",symbol_table[i].address);
		printf("\n");
		i++;
	}
}

void create_symbol_node(char *name, char *value, char *type, int address){
	int check = symbol_lookup(name);
	if(check==0){
		int mem = get_mem_index();
		if(mem != 100){
			symbol_table[symbol_index].address=mem;
		}
		else{
			symbol_table[symbol_index].address=address;
		}				
		symbol_table[symbol_index].name=name;
   		symbol_table[symbol_index].value=value;
		symbol_table[symbol_index].type=type;
		symbol_index++;
	}
}

int symbol_lookup(char *name){
	int i=0, true=0;
	for(i=0; i<symbol_index;i++){
		if(strcmp(symbol_table[i].name,name)==0){
			true=1;
			break;
		}
	}
	return true;
}

symbol_node lookup(char *name){
	int i=0; 
	symbol_node temp;
	for(i=0; i<symbol_index;i++){
		if(strcmp(symbol_table[i].name,name)==0){
			temp = symbol_table[i];
			break;
		}
	}
	return temp;
}

int get_mem_index(){
	int temp = memory_index;
	if(memory_index < 100){
		memory_index++;
		return temp;
	}
	else{
		return 100;
	}
}


int get_register_index(){
	int temp = register_index;
	if(register_index < 10){
		register_index++;
		return temp;
	}
	else{
		return 10;
	}
}


int codegen(node *p) {
	if(!p){
		printf("ret 0\n");		
	}
	else{
		if(strcmp(p->childnode->siblings->siblings->val,"FUNCTIONS")==0){
			//printf("\n");
		}
		if(strcmp(p->childnode->siblings->siblings->siblings->siblings->val,"MAIN")==0){
			node *temp = p->childnode->siblings->siblings->siblings->siblings->siblings;//statements node
			if(temp!=NULL){
				temp = temp->childnode;//statement node
				while(temp!=NULL){
					if(strcmp(temp->val,"statement")==0){
						if(strcmp(temp->childnode->val,"read_stmt")==0){
							node *tempchild = temp->childnode->childnode->siblings;
							int count = 0;
							while(tempchild!=NULL){
								if(strcmp(tempchild->val,"idplus")==0){
									count++;
									if(count<3){
										symbol_node sym = lookup(tempchild->childnode->val);
										fprintf(fp,"read M[%d];\n",sym.address);
									}
									else{
										break;
									}
								}
								tempchild=tempchild->siblings;
							}
						}
						if(strcmp(temp->childnode->val,"print_stmt")==0){
							node *tempchild = temp->childnode->childnode->siblings;//print_param_plus nodes
							int count = 0;
							fprintf(fp,"print ");
							while(tempchild!=NULL){
								if(strcmp(tempchild->val,"print_param_plus")==0){
									node *t = tempchild->childnode;//
									if(strcmp(t->childnode->val,"scalar_param")==0){
										//printf("%s ",t->childnode->childnode->val);
										fprintf(fp,"%s ",t->childnode->childnode->val);
									}
									else{
										symbol_node sym = lookup(t->childnode->val);
										//printf("%s ",sym.value);
										fprintf(fp,"M[%d] ",sym.address);
									}
								}
								tempchild=tempchild->siblings;
							}
							fprintf(fp,";\n");
						}
						if(strcmp(temp->childnode->val,"assgn_stmt")==0){
							node *tempnode = temp->childnode->childnode->siblings->siblings;//paramters of assgn
							symbol_node sym_id = lookup(temp->childnode->childnode->siblings->val);
							if(strcmp(tempnode->childnode->val,"function_call")!=0){
								int check_symbol = symbol_lookup(tempnode->childnode->val);
								if(check_symbol==1){
									symbol_node sym = lookup(tempnode->childnode->val);
									int reg_ind = get_register_index();
									fprintf(fp,"load R%d %s;\n",reg_ind, sym.value);
									fprintf(fp,"store M[%d] R%d;\n",sym_id.address,reg_ind);
									register_index--;
								}
								else{
									int reg_ind = get_register_index();
									fprintf(fp,"load R%d %s;\n",reg_ind, tempnode->childnode->val);
									fprintf(fp,"store M[%d] R%d;\n",sym_id.address,reg_ind);
									register_index--;
								}
							}
						}
					}
					temp=temp->siblings;
					if(temp!=NULL){
						temp=temp->childnode;
					}
				}
			}
		}
	}
	return 0;
}

int main (int argc, char **argv) {
	yy_flex_debug = 1;
	/*if(argc > 1) {
		FILE *file;
		file = fopen(argv[2], "r");
		if(!file) {
			fprintf(stderr, "could not open %s \n", argv[2]);
			exit(1);
		}
		yyin = file;
	}*/
	yyparse ( );
	printf("SYMBOL TABLE:\n");
	print_symbol_table();

   	fp = fopen(argv[1], "w+");
	int c = codegen(rootnode);
	fclose(fp);
	return 0;
}

void yyerror (char *s) 
{
	fprintf (stderr, "%s\n", s);
} 
