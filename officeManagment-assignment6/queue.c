
/*
AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST
DATE CREATED: 3rd OCT 2021
DATE MODIFIED: 6th OCT 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include"queue.h"
#include<stdlib.h>
 //checks if the queue is empty
_Bool isEmpty(queueType s1)
{
    if((s1.top == NULL) || (s1.countt == 0))
        return true;
    else
        return false;
        

}

_Bool isFull (queueType s)
{
    return false;
}


//creates a queue and initialises the count to 0 and the top and rear to null
queueType createqueue()
{
    queueType s;
    s.countt = 0;
    s.top = NULL;
    s.rear=NULL;
    return s;
}

//creates a new node and puts the entered element in the node
_Bool enqueue(int clientid, eleType budget, queueType *s1)
{
   node *newDatanode = ( node *)malloc(1*sizeof(node));
   if (newDatanode == NULL)
   {
       return false;
   }
   else
   {
     newDatanode -> clientid = clientid;
     newDatanode -> budget = budget;
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


//takes the values clientid and budget and puts it into a new node
_Bool enqueueall(int clientid, eleType budget, eleType fees, eleType amtspent, queueType *s1)
{
   node *newDatanode = ( node *)malloc(1*sizeof(node));
   if (newDatanode == NULL)
   {
       return false;
   }
   else
   {
     newDatanode -> clientid = clientid;
     newDatanode -> budget = budget;

     newDatanode -> fees = fees;
     newDatanode -> amtspent = amtspent;

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


//marks the offer as complete
 void complete(int f, int as ,queueType *s1, queueType *s2)
{
    int fees, amtspent, budget, clientid;

    node * temp = s1->top;

    
    budget = temp -> budget;
    //deadline = temp -> deadline;
    clientid = temp -> clientid;

    s1->top = s1->top->next;

    enqueueall(clientid, budget, f, as, s2); 
      

    //eleType dequeuepedEle = temp->data;
    //free(temp);
    s1->countt--;
    return;
}

//displays the offers in the shop and home renovation
void Display(queueType s1)
{

  node *temp=s1.top;
  printf("\n OFFERS: \n ");
  while(temp!=NULL)
  {

    printf("\n %d  ", temp->clientid);
    printf("\n %d  ", temp->budget);
    //printf("\n %c  ", temp->deadline);

    temp = temp->next;

  }

}

/*void DisplayShop(queueType s2)
{

  node *temp=s2.top;
  printf("the elements in the queue are : \n ");
  while(temp!=NULL)
  {

    printf("%c  ", temp->clientid);
    printf("%d  ", temp->budget);
    printf("%c  ", temp->deadline);
    
    temp = temp->next;

  }

}*/

// displays the offers in the complete queues 
void DisplayComplete(queueType s2)
{

  node *temp=s2.top;
  printf("the elements in the queue are : \n ");
  while(temp!=NULL)
  {

    printf("%d  ", temp->clientid);
    printf("%d  ", temp->budget);
    //printf("%c  ", temp->deadline);
    printf("%d  ", temp->fees);
    printf("%d  ", temp->amtspent);
    temp = temp->next;

  }

}

//distroys the created queues
void destroyqueue(queueType *s1) {
    node *temp;
    while(s1->top != NULL) {
        temp = s1->top;
        s1->top = temp->next;
        free(temp) ;
        s1->countt--;
    }
}

//function to calculate the total profit earned
void profitearned(queueType s1, queueType s2)
{
              int totalfeesHome, amountspentHome,totalfeesShop, amountspentShop, profitHome, profitShop, totalprofit;
              if (!isEmpty(s1))
              {
                //printf("\n profitHome entered");
                profitHome = profit(s1);
              }
              if (isEmpty(s1))
              {
                profitHome = 0;
              }
              if (!isEmpty(s2))
              {
                //printf("\n profitShop entered");
  
                profitShop = profit(s2);
              }
              if (isEmpty(s2))
              {
                profitShop = 0;
              }
              totalprofit = profitHome+profitShop;
              printf("the total profit is %d ", totalprofit);
              //totalprofit = profitShop+profitHome;
return;
}

//function to calculate the profit earned 
int profit(queueType s1)
{
  int totalfees=0, amountspent=0, totalprofit=0;

  node *temp = s1.top;

  while (temp!=NULL)
  {
    totalfees = totalfees + temp->fees;
    amountspent = amountspent + temp->amtspent;

    temp = temp->next;
  }
  totalprofit = totalfees-amountspent;

return totalprofit;
}