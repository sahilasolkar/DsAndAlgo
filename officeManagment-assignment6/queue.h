
/*
AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST
DATE CREATED: 3rd OCT 2021
DATE MODIFIED: 6th OCT 2021
*/
// DS DEVELOPER


#ifndef _queue_H
#define _queue_H
//data
typedef int eleType;
struct queue
{

    struct qnode *top;
    struct qnode *rear;
    int countt;
};

typedef struct queue queueType;

struct qnode
{

  //eleType data;
  struct qnode *next;
  int clientid;
  eleType budget;
  //char deadline[100];
  eleType fees;
  eleType amtspent;

};


typedef struct qnode node;
//opertations
_Bool isEmpty(queueType s);
_Bool isFull (queueType s);
_Bool enqueue(int clientid, eleType budget, queueType *s1);
_Bool qenqueueall(int clientid, eleType budget,eleType fees, eleType amtspent, queueType *s1);
void complete(int fees, int amtspent ,queueType *s1, queueType *s2);
void completeShop(int fees, int amtspent ,queueType *s1);
eleType peek (queueType *s1);
void destroyqueue(queueType *s1);
queueType createqueue();
void Display(queueType s1);
void DisplayComplete(queueType s2);
void profitearned(queueType s1, queueType s2);
int profit(queueType s1);
//eleType profitComp(queueType s1);
#endif