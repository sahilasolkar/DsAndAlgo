/*
AUTHOR : SAHIL.A
PROGRAM: POSTFIX EVALUATION
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPER

#include<stdbool.h>
#include<stdlib.h>
#include "2107_stack.h"

//checks if the stack is empty
_Bool isempty(stackType s1){
	if(s1.top==NULL){
		return true;
	}
	return false;
}

//checks if the stack is full
_Bool isfull(stackType s1){
	return false;
	
}

//peek fn
eleType peek(stackType s1){
	return s1.top->data;
}


//create stack
stackType createStack(){
	stackType s;
	s.count = 0;
	s.top = NULL;
	return s;
}

//push fn 
_Bool push(eleType ip_data,stackType *s1){
	
	node *newDataNode = (node *) malloc(1* sizeof(node)); // allocate memory
	if(newDataNode == NULL)
		return false;	
	else{
		newDataNode->data = ip_data;
		newDataNode->next = s1->top;
		s1->top = newDataNode;
		s1->count++;
		return true;
	}
}


//pop 
eleType pop(stackType *s1){
	s1->count--;
	node *temp = s1->top;
	s1->top = s1->top->next;
	eleType poppedEle = temp->data;
	free(temp);
	return (poppedEle);	
}

//destroy
void destroyStack(stackType *s1){
	while(s1->top!=NULL){
		s1->count--;
		node *temp = s1->top;
		s1->top = s1->top->next;
		free(temp);
	}	
}