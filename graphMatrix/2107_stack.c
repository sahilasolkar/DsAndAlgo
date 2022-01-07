/*
    AUTHOR: SAHIL.A 2107
    PROGRAM: STACK USING LINKEDLIST. 
    DATE CREATED: 1 NOV 2021
    DATE MODIFIED: 1 NOV 2021
*/
//DS Designer
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2107_stack.h"

//creates a new stack
stackType stackCreate()
{ 
    stackType s;
    s.count = 0;
    s.top = NULL;
    return s;
}

//to check if the stack is empty 
bool stackIsEmpty(stackType s1)
{
    if((s1.top == NULL) || (s1.count == 0))
        return true;
    else
        return false;
}

//to check if the stack is full
bool stackIsFull(stackType s1)
{ 
    return false;
}

//pushes a value onto the stack
bool stackPush(sEleType value, stackType *s1)
{ 
    snode *temp = (snode *)malloc(1 * sizeof(snode)); //Allocate mem for the new node
    if(temp == NULL)
        return false;
    temp->data = value;
    temp->next = s1->top;
    s1->top = temp;
    s1->count++;
    return true;
}

//returns the top elemtent of the stack
sEleType stackPeek(stackType s1)
{ 
    return s1.top->data;
}

//Removes the top element of the stack
sEleType stackPop(stackType *s1)
{ 
    sEleType value;
    snode *temp = s1->top;
    s1->top = s1->top->next;
    value = temp->data;
    free(temp); //Deallocate memory of node
    s1->count--;
    return value;
}


//Deletes the stack
void stackDelete(stackType *s1)
{ 
    snode *temp;
    while(s1->top != NULL){
        temp = s1->top;
        s1->top = s1->top->next;
        free(temp); //Deallocate memory allocated to the nodes
        s1->count--;
    }
}