
/*AUTHOR : SAHIL.A 2107
PROGRAM: queue USING LINKED LIST.
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 26th SEPT 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include"2107_queue.h"
#include<stdlib.h>

_Bool isEmpty(queueType s1)
{
    if((s1.top == NULL) || (s1.countt == 0))
        return true;
    else
        return false;
        

}
//needs further improvement
_Bool isFull (queueType s)
{
    return false;
}

eleType peek (queueType *s1)
{
    return s1->top->data;
}

queueType createqueue()
{
    queueType s;
    s.countt = 0;
    s.top = NULL;
    s.rear=NULL;
    return s;
}

_Bool enqueue(eleType ip_data, queueType *s1)
{
   node *newDatanode = ( node *)malloc(1*sizeof(node));
   if (newDatanode == NULL)
   {
       return false;
   }
   else
   {
     newDatanode -> data = ip_data;
     newDatanode -> next = NULL;
      if (s1->countt==0){
    
       
       /*if (s1->top == NULL) //case of enqueue is an empty queue
       {

           newDatanode->next = NULL;
           s1->top = newDatanode;
           s1->count++;
       }
       else  //in the case of a non empty queue
       {
           s1->top = newDatanode;
           s1->count++;  //since this is same for both the conditions we can move it out
           newDatanode->next = s1->top; // this line applies to both the conditions so we can remove it

       }*/
       //newDatanode->next = s1->top; // this line is a replacement to the commented if else block
       s1->top = newDatanode;
       s1->rear= newDatanode;
       s1->countt++;
     }
      else
     {
       //newDatanode->next = s1->rear;
       s1->rear->next = newDatanode;
       s1->rear = newDatanode;
       s1 ->countt++;
     }
       return true;
   }
}

eleType dequeue(queueType *s1)
{
    node * temp = s1->top;
    //printf("done");
    /*if (s1->top->next == NULL)
    {
        s1->top = s1->top->next;
    }
    else
    {
        s1->top = s1->top->next;

    }*/
    s1->top = s1->top->next; //replacement for the commented if else
    eleType dequeuepedEle = temp->data;
    free(temp);
    s1->countt--;
    
    return dequeuepedEle;
}

void Display(queueType s1)
{

  node *temp=s1.top;
  printf("the elements in the queue are : \n ");
  while(temp!=NULL)
  {

    //printf("%d  ", temp->data);
    temp = temp->next;

  }

}

void destroyqueue(queueType *s1) {
    node *temp;
    while(s1->top != NULL) {
        temp = s1->top;
        s1->top = temp->next;
        free(temp) ;
        s1->countt--;
    }
}
