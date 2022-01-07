
/*
AUTHOR : SAHIL.A
PROGRAM: BINARY SEARCH TREE. LIB HEADER FILE
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPER

#ifndef _STACK_H
	#define _STACK_H
	
	typedef int eleType;

	struct stack{
		
		struct stack_node * top;
		int count;
	};
	typedef struct stack stackType;
	
	struct stack_node{
		eleType data;
		struct stack_node *next;
	};
	typedef struct stack_node node;
	

	_Bool isempty(stackType);	
	_Bool isfull(stackType);
	_Bool push(eleType, stackType *);
	eleType pop(stackType *);
	eleType peek(stackType);
	stackType createStack();	
	void destroyStack(stackType *);
	
#endif