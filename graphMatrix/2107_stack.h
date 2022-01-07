/*
    AUTHOR: SAHIL.A 2107
    PROGRAM: STACK USING LINKEDLIST. lib
    DATE CREATED: 1 NOV 2021
    DATE MODIFIED: 1 NOV 2021
*/
//DS Designer
#ifndef STACK_H
    #define STACK_H
    typedef char sEleType;
    typedef struct stack_node snode;
    typedef struct stack stackType;

    struct stack{
        snode *top;
        int count;
    };

    struct stack_node{
        sEleType data;
        struct stack_node *next;
    };
    
    stackType stackCreate();
    _Bool stackIsEmpty(stackType);
    _Bool stackIsFull(stackType);
    _Bool stackPush(sEleType, stackType *);
    sEleType stackPop(stackType *);
    sEleType stackPeek(stackType);
    void stackDelete(stackType *);
#endif