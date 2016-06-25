#ifndef FP_H
#define FP_H
#include <stdio.h>
#include <malloc.h>

//parse tree structure
typedef struct node{
	char *val;
	struct node *childnode;
	struct node *siblings;
} node;
node *create_node(char *nodevalue);
node *create_node1(node *tempnode);
void in_order_traversal(node *tempnode, int print_index);

//symbol table node
typedef struct symbol_node{
	char *name;
	char *value;
	char *type;
	int address;	
} symbol_node;

void create_symbol_node(char *name, char *value, char *type, int address);
struct symbol_node symbol_table[1000];
void print_symbol_table();
int symbol_lookup(char *name);
symbol_node lookup(char *name);
#endif