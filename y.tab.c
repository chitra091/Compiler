#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "FP.yacc"
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
#line 21 "FP.yacc"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {char* string_val; node *nodetype;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define exit_command 257
#define constant 258
#define function 259
#define mainkey 260
#define readkey 261
#define printkey 262
#define returnkey 263
#define ifkey 264
#define thenkey 265
#define elsekey 266
#define loop 267
#define whilekey 268
#define equal 269
#define predefined 270
#define comparison_op 271
#define open_spl_char 272
#define close_spl_char 273
#define boolean 274
#define integer_value 275
#define float_value 276
#define identifier 277
#define string 278
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    2,    2,    3,    4,    4,    4,    1,    1,    5,
    5,    6,    7,    7,    8,    8,    9,    9,    9,    9,
    9,    9,   10,   11,   12,   12,   13,   14,   14,   15,
   15,   16,   16,   16,   17,   18,   18,   19,   19,   20,
   21,   22,   23,   23,   24,
};
static const short yylen[] = {                            2,
    6,    2,    0,    4,    1,    1,    1,    1,    1,    2,
    0,    7,    2,    1,    2,    0,    1,    1,    1,    1,
    1,    1,    5,    4,    2,    1,    4,    2,    1,    1,
    1,    1,    1,    1,    4,    1,    1,    2,    0,    8,
    5,    5,    5,    3,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    2,    6,    8,
    9,    7,    5,    0,    0,    0,    0,    4,   37,   36,
    0,    0,   10,    0,    0,    0,    1,    0,   17,   18,
   19,   20,   21,   22,   13,    0,    0,    0,    0,    0,
    0,    0,   15,    0,    0,    0,   30,   31,    0,    0,
    0,    0,    0,    0,    0,    0,   25,   24,   27,   28,
   45,    0,    0,    0,    0,    0,    0,   33,   34,    0,
   32,   12,   44,    0,    0,   41,   42,    0,   23,    0,
    0,    0,    0,   43,    0,   38,   35,   40,
};
static const short yydgoto[] = {                          2,
   69,    4,    5,   48,   16,   17,   25,   27,   28,   29,
   30,   46,   31,   49,   50,   82,   71,   21,   83,   32,
   33,   34,   52,   63,
};
static const short yysindex[] = {                      -254,
 -267,    0, -247, -249, -267, -243, -233,    0,    0,    0,
    0,    0,    0, -250, -262, -222, -233,    0,    0,    0,
 -236, -230,    0, -236, -220, -255,    0, -230,    0,    0,
    0,    0,    0,    0,    0, -232, -229, -257, -228, -227,
 -228, -226,    0, -230, -229, -224,    0,    0, -221, -257,
 -234, -218, -230, -230, -248, -219,    0,    0,    0,    0,
    0, -217, -248, -230, -216, -215, -262,    0,    0, -214,
    0,    0,    0, -248, -211,    0,    0, -248,    0, -213,
 -230, -248, -212,    0, -210,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
 -197,    0,    0,    0, -197,    0, -196,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -196,    0,    0,    0,
    0,   65,    0, -195,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -207, -206,    0,    0,    0,    0, -204,
    0,    0, -207, -207,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -194,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -203,    0,    0,
 -207, -203,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   -4,   66,    0,   67,   57,    0,   51,  -28,    0,    0,
    0,   31,    0,   27,    0,  -52,    0,   11,   -3,    0,
    0,    0,   39,    0,
};
#define YYTABLESIZE 274
static const short yytable[] = {                         43,
   16,   13,   70,    1,    3,   37,   38,   19,   39,    7,
   74,   40,   41,   42,   20,   56,    9,   10,   11,   47,
   12,   80,   18,   67,   65,   66,   10,   11,   68,    6,
    9,   10,   11,   13,   12,   75,   61,   22,   15,   62,
   24,   26,   36,   51,   44,   13,   64,   45,   58,   53,
   55,   59,   85,   72,   81,   73,   76,   77,   79,   84,
   87,    3,   88,   11,   16,   16,   26,   14,   29,   39,
    8,   16,   14,   23,   35,   57,   60,   78,   86,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,    0,
    0,    0,    0,   16,
};
static const short yycheck[] = {                         28,
    0,    6,   55,  258,  272,  261,  262,  270,  264,  259,
   63,  267,  268,  269,  277,   44,  274,  275,  276,  277,
  278,   74,  273,  272,   53,   54,  275,  276,  277,  277,
  274,  275,  276,   38,  278,   64,  271,  260,  272,  274,
  277,  272,  263,  272,  277,   50,  265,  277,  273,  277,
  277,  273,   81,  273,  266,  273,  273,  273,  273,  273,
  273,  259,  273,  260,    0,  273,  273,  263,  273,  273,
    5,  266,    6,   17,   24,   45,   50,   67,   82,   41,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,   -1,
   -1,   -1,   -1,  273,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"exit_command","constant",
"function","mainkey","readkey","printkey","returnkey","ifkey","thenkey",
"elsekey","loop","whilekey","equal","predefined","comparison_op",
"open_spl_char","close_spl_char","boolean","integer_value","float_value",
"identifier","string",
};
static const char *yyrule[] = {
"$accept : program",
"program : constant constantdefs function functiondefs mainkey statements",
"constantdefs : constantdef constantdefs",
"constantdefs :",
"constantdef : open_spl_char identifier scalar_param close_spl_char",
"scalar_param : number",
"scalar_param : boolean",
"scalar_param : string",
"number : integer_value",
"number : float_value",
"functiondefs : functiondef functiondefs",
"functiondefs :",
"functiondef : open_spl_char function_name args returnkey identifier statements close_spl_char",
"args : identifier args",
"args : identifier",
"statements : statement statements",
"statements :",
"statement : assgn_stmt",
"statement : read_stmt",
"statement : print_stmt",
"statement : if_stmt",
"statement : loop_stmt",
"statement : while_stmt",
"assgn_stmt : open_spl_char equal identifier parameter close_spl_char",
"read_stmt : open_spl_char readkey idplus close_spl_char",
"idplus : identifier idplus",
"idplus : identifier",
"print_stmt : open_spl_char printkey print_param_plus close_spl_char",
"print_param_plus : print_param print_param_plus",
"print_param_plus : print_param",
"print_param : identifier",
"print_param : scalar_param",
"parameter : function_call",
"parameter : identifier",
"parameter : number",
"function_call : open_spl_char function_name parameters close_spl_char",
"function_name : identifier",
"function_name : predefined",
"parameters : parameter parameters",
"parameters :",
"if_stmt : open_spl_char ifkey expr thenkey statements elsekey statements close_spl_char",
"loop_stmt : open_spl_char loop identifier statements close_spl_char",
"while_stmt : open_spl_char whilekey expr statements close_spl_char",
"expr : open_spl_char co_op parameter parameter close_spl_char",
"expr : open_spl_char boolean close_spl_char",
"co_op : comparison_op",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 209 "FP.yacc"
                     /* C code */

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
										fprintf(fp,"read M[%d]\n",sym.address);
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
							fprintf(fp,"\n");
						}
						if(strcmp(temp->childnode->val,"assgn_stmt")==0){
							node *tempnode = temp->childnode->childnode->siblings->siblings;//paramters of assgn
							symbol_node sym_id = lookup(temp->childnode->childnode->siblings->val);
							if(strcmp(tempnode->childnode->val,"function_call")!=0){
								int check_symbol = symbol_lookup(tempnode->childnode->val);
								if(check_symbol==1){
									symbol_node sym = lookup(tempnode->childnode->val);
									int reg_ind = get_register_index();
									fprintf(fp,"load R[%d] %s\n",reg_ind, sym.value);
									fprintf(fp,"store M[%d] R[%d]\n",sym_id.address,reg_ind);
									register_index--;
								}
								else{
									int reg_ind = get_register_index();
									fprintf(fp,"load R[%d] %s\n",reg_ind, tempnode->childnode->val);
									fprintf(fp,"store M[%d] R[%d]\n",sym_id.address,reg_ind);
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
#line 537 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 52 "FP.yacc"
	{yyval.nodetype=create_node("program");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-5].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-4].nodetype);
															 yyval.nodetype->childnode->siblings->siblings=create_node(yystack.l_mark[-3].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings=create_node1(yystack.l_mark[-2].nodetype);
															 yyval.nodetype->childnode->siblings->siblings->siblings->siblings=create_node(yystack.l_mark[-1].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings->siblings->siblings=create_node1(yystack.l_mark[0].nodetype);
															 rootnode=yyval.nodetype;
															 printf("PARSE TREE\n");
															 in_order_traversal(rootnode,print_index);
															 }
break;
case 2:
#line 64 "FP.yacc"
	{yyval.nodetype=create_node("constantdefs");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-1].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[0].nodetype);}
break;
case 3:
#line 67 "FP.yacc"
	{yyval.nodetype=NULL;}
break;
case 4:
#line 69 "FP.yacc"
	{yyval.nodetype=create_node("constantdef");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-1].nodetype);
															 create_symbol_node(yystack.l_mark[-2].string_val,yystack.l_mark[-1].nodetype->childnode->val,"string",999);}
break;
case 5:
#line 74 "FP.yacc"
	{yyval.nodetype=create_node("scalar_param");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
case 6:
#line 76 "FP.yacc"
	{yyval.nodetype=create_node("scalar_param");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
case 7:
#line 78 "FP.yacc"
	{yyval.nodetype=create_node("scalar_param");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
case 8:
#line 81 "FP.yacc"
	{yyval.string_val=yystack.l_mark[0].string_val;}
break;
case 9:
#line 82 "FP.yacc"
	{yyval.string_val=yystack.l_mark[0].string_val;}
break;
case 10:
#line 84 "FP.yacc"
	{yyval.nodetype=create_node("functiondefs");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-1].nodetype);
															 yyval.nodetype->childnode->siblings=(yystack.l_mark[0].nodetype);}
break;
case 11:
#line 87 "FP.yacc"
	{yyval.nodetype=NULL;}
break;
case 12:
#line 89 "FP.yacc"
	{yyval.nodetype=create_node("functiondef");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-5].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-4].nodetype);
															 yyval.nodetype->childnode->siblings->siblings=create_node(yystack.l_mark[-3].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);
															 create_symbol_node(yystack.l_mark[-2].string_val,NULL,"string",999);}
break;
case 13:
#line 97 "FP.yacc"
	{yyval.nodetype=create_node("args");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-1].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[0].nodetype);
															 create_symbol_node(yystack.l_mark[-1].string_val,NULL,"string",999);}
break;
case 14:
#line 101 "FP.yacc"
	{yyval.nodetype=create_node("args");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);
															 create_symbol_node(yystack.l_mark[0].string_val,NULL,"string",999);}
break;
case 15:
#line 105 "FP.yacc"
	{yyval.nodetype=create_node("statements");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-1].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[0].nodetype);}
break;
case 16:
#line 108 "FP.yacc"
	{yyval.nodetype=NULL;}
break;
case 17:
#line 110 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 18:
#line 112 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 19:
#line 114 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 20:
#line 116 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 21:
#line 118 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 22:
#line 120 "FP.yacc"
	{yyval.nodetype=create_node("statement");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 23:
#line 123 "FP.yacc"
	{yyval.nodetype=create_node("assgn_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-3].string_val);
															 yyval.nodetype->childnode->siblings=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);
															 create_symbol_node(yystack.l_mark[-2].string_val,NULL,"string",999);}
break;
case 24:
#line 129 "FP.yacc"
	{yyval.nodetype=create_node("read_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 25:
#line 133 "FP.yacc"
	{yyval.nodetype=create_node("idplus");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-1].string_val);
															 yyval.nodetype->siblings=create_node1(yystack.l_mark[0].nodetype);
															 create_symbol_node(yystack.l_mark[-1].string_val,NULL,"string",999);}
break;
case 26:
#line 137 "FP.yacc"
	{yyval.nodetype=create_node("idplus");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);
															 create_symbol_node(yystack.l_mark[0].string_val,NULL,"string",999);}
break;
case 27:
#line 141 "FP.yacc"
	{yyval.nodetype=create_node("print_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 28:
#line 145 "FP.yacc"
	{yyval.nodetype=create_node("print_param_plus");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-1].nodetype);
															 yyval.nodetype->siblings=create_node1(yystack.l_mark[0].nodetype);}
break;
case 29:
#line 148 "FP.yacc"
	{yyval.nodetype=create_node("print_param_plus");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 30:
#line 151 "FP.yacc"
	{yyval.nodetype=create_node("print_param");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);
															 create_symbol_node(yystack.l_mark[0].string_val,NULL,"string",999);}
break;
case 31:
#line 154 "FP.yacc"
	{yyval.nodetype=create_node("print_param");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 32:
#line 157 "FP.yacc"
	{yyval.nodetype=create_node("paramter");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[0].nodetype);}
break;
case 33:
#line 159 "FP.yacc"
	{yyval.nodetype=create_node("parameter");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);
															 create_symbol_node(yystack.l_mark[0].string_val,NULL,"string",999);}
break;
case 34:
#line 162 "FP.yacc"
	{yyval.nodetype=create_node("parameter");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
case 35:
#line 165 "FP.yacc"
	{yyval.nodetype=create_node("function_call");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-2].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 36:
#line 169 "FP.yacc"
	{yyval.nodetype=create_node("funtion_name");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);
															 create_symbol_node(yystack.l_mark[0].string_val,NULL,"string",999);}
break;
case 37:
#line 172 "FP.yacc"
	{yyval.nodetype=create_node("funtion_name");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
case 38:
#line 175 "FP.yacc"
	{yyval.nodetype=create_node("parameters");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-1].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[0].nodetype);}
break;
case 39:
#line 178 "FP.yacc"
	{yyval.nodetype=NULL;}
break;
case 40:
#line 180 "FP.yacc"
	{yyval.nodetype=create_node("if_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-6].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-5].nodetype);
															 yyval.nodetype->childnode->siblings->siblings=create_node(yystack.l_mark[-4].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings=create_node1(yystack.l_mark[-3].nodetype);
															 yyval.nodetype->childnode->siblings->siblings->siblings->siblings=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings->siblings->siblings->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 41:
#line 188 "FP.yacc"
	{yyval.nodetype=create_node("loop_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-3].string_val);
															 yyval.nodetype->childnode->siblings=create_node(yystack.l_mark[-2].string_val);
															 yyval.nodetype->childnode->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);
															 create_symbol_node(yystack.l_mark[-2].string_val,NULL,"string",999);}
break;
case 42:
#line 194 "FP.yacc"
	{yyval.nodetype=create_node("while_stmt");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-3].string_val);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-2].nodetype);
															 yyval.nodetype->childnode->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 43:
#line 199 "FP.yacc"
	{yyval.nodetype=create_node("expr");
															 yyval.nodetype->childnode=create_node1(yystack.l_mark[-3].nodetype);
															 yyval.nodetype->childnode->siblings=create_node1(yystack.l_mark[-2].nodetype);
															 yyval.nodetype->childnode->siblings->siblings=create_node1(yystack.l_mark[-1].nodetype);}
break;
case 44:
#line 203 "FP.yacc"
	{yyval.nodetype=create_node("expr");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[-1].string_val);}
break;
case 45:
#line 206 "FP.yacc"
	{yyval.nodetype=create_node("co_op");
															 yyval.nodetype->childnode=create_node(yystack.l_mark[0].string_val);}
break;
#line 1010 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
