
/*
AUTHOR : SAHIL.A 2107
PROGRAM: queue USING LINKED LIST. lib
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 26th SEPT 2021
*/
// DS DEVELOPER


#ifndef _queue_H
#define _queue_H
//data
typedef char eleType;
struct queue
{

    struct qnode *top;
    struct qnode *rear;
    int countt;
};

typedef struct queue queueType;

struct qnode
{
    eleType data;
    struct qnode *next;
};


typedef struct qnode node;
//opertations
_Bool isEmpty(queueType s);
_Bool isFull (queueType s);
_Bool enqueue(eleType ele, queueType *s1);
eleType dequeue(queueType *s1);
eleType peek (queueType *s1);
void destroyqueue(queueType *s1);
queueType createqueue();
void Display(queueType s1);
#endif
