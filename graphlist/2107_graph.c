/*AUTHOR : SAHIL.A
PROGRAM: GRAPH USING ADJACENCY LIST.
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include"2107_graph.h"
#include"2107_queue.h"
#include<stdlib.h>
#include <string.h>

//create graph fn 
graphNd * createGraph()
{
  graphNd *newGraph = (graphNd *) malloc(sizeof (graphNd));

  if (newGraph)
  {
    newGraph->firstVertex=NULL;
    newGraph->vertexCount=0;
  }
  return newGraph;
}

//insert fn
int insert(graphNd * graph, char name[])
{
  vertexNd * newvertex =(vertexNd *) malloc (sizeof(vertexNd));

  //if couldnt create a newvertex, return -1
  if (newvertex==NULL)
  {
    return -1;
  }
  //if the new vertex is created, 
  //copy the contents of the string you entered to the "name" in newvertex
  strcpy(newvertex->name, name); 
  //set the indegree, outdegree, processed to zero
  newvertex->in_degree=0;
  newvertex->out_degree=0;
  newvertex->processed=0;
  //set the firstlink and the nextvertex to null
  newvertex->firstLink=NULL;
  newvertex->nextVertex=NULL;
  //special case while entering the first vertex
  if (graph->firstVertex==NULL)
  {
    graph->firstVertex=newvertex;
    graph->vertexCount++;
  }
  //while entering vertices other than the first
  else
  {
    //make a temporary vertex pointer than holds the firstvertex in the vertex list
    vertexNd * temp = graph->firstVertex;
    //iterate until you reach the end of the list
    while(temp->nextVertex!=NULL)
    {
      temp=temp->nextVertex;
    }
    //here you reach the end, then put the new vertex here.
    temp->nextVertex=newvertex;
  }
  //return 1 to indicate success
  return 1;
}

//inserts an edge between two vertices
int insertEdge(graphNd *graph, char src[], char dest[])
{
  //check if the source and the destination exists
  //if the destination is not found then return -3
  vertexNd *source = locate(graph, src); 
  if(!source)
  {
    return -2;
  }

  //if the source is not found then return -2
  vertexNd *destination = locate(graph, dest);
  if(!destination)
  {
    return -3;
  }

  //if both the dest and the source are found then, 
  //allocate memory
  linkNd *newlink =(linkNd *) malloc (sizeof(linkNd));
  
  //if the memory is not allocated then return 1
  if(!newlink)
  {
    return -1;
  }

  //initialise the new link node
  //the destination holds the pointer to the destination vertex
  newlink->destination=destination;
  //the nextlink is null
  newlink->nextLink=NULL;

  //special case when adding the first edge to a vertex
  if (source->firstLink==NULL)
  {
    source->firstLink=newlink;
  }
  //when its not the first edge,
  else
  {
    //create a temp linknode pointer
    linkNd * templink= source->firstLink;
    //iterate through each linknode until you reach the end
    while (templink->nextLink!=NULL)
    {
      templink=templink->nextLink;
    }
    //here you reach the end. insert the newlinknode
    templink->nextLink=newlink;
  }
  //increment the outdegree of the source 
  source->out_degree++;
  //increment the indegree of the destination
  destination->in_degree++;
  //return 1 for succesful insertion of an egde
  return 1;
}

//to check if the stack is empty
_Bool isEmptystack(stackType s1)
{
    if (s1.top ==NULL)
    {
        return true;
    }
    return false;
}

//fn to locate the presence of a given vertex
//returns null if the vertex is not present
//returns a pointer to the vertex if the vertex is present
vertexNd * locate(graphNd *graph, char check[])
{
  //if the graph is not empty
  if (graph->firstVertex!=NULL)
  {
    //make a new temperory vertex node pointer
    vertexNd *temp = graph->firstVertex;
    //iterate through every vertex till you reach the end
    while(temp!=NULL)
    {
      //strcmp(a,b) returns 0 if the a and b have the same value
      if(strcmp(temp->name,check)==0) 
      {
        return temp;
      }
      temp=temp->nextVertex;
    } 
  }
  return NULL;
}

int deleteVertex(graphNd *graph, char val[])
{
  char check[20];
  strcpy(check, val);
  //first check if the vertex exists using the locate fn
  vertexNd *tempvertex = locate(graph, check);
  //temp holds the first vertex
  vertexNd *temp = graph->firstVertex; 
  vertexNd *temp1= graph->firstVertex;
  linkNd *templink;
  //if the value is not found then return -1 
  if (tempvertex==NULL)
  {
    return -1;
  }
  //if the vertex is found then check if the vertex has any links(for firstvertex)
  else if (temp==tempvertex)
  {
    //if the vertex has links, return -2
    if(temp->firstLink!=NULL)
    {
      return -2;
    }
    //if the vertex has no links, return 1
    else
    {
      graph->firstVertex=temp->nextVertex;
      free(temp);
      return 1;
    }
  }
  //if the vertex has links, return -2
  else if(tempvertex->firstLink==NULL)
  {
    return -2;
  }
  //if the vertex has no links, remove the vertex and also remove all its instances as links in other vertices, return 1
  else 
  {
    vertexNd *tempvert;
    while(temp->nextVertex!=tempvertex)
    {
      temp=temp->nextVertex;
    }
    tempvert=temp->nextVertex;
    temp->nextVertex=tempvert->nextVertex;
    free(tempvert);

    //to remove all the instances of the deleted vertex from all the vertices if present
    while(temp1!=NULL)
    {
      templink=temp1->firstLink;
      while(templink!=NULL)
      {
        //if the first link node is the deleted vertex node
        if(temp1->firstLink->destination==tempvertex)
        {
          temp1->firstLink=templink->nextLink;
          free(templink);
        }
        else if (templink->nextLink->destination==tempvertex)
        {
          linkNd * currentlink=templink->nextLink;
          templink->nextLink=currentlink->nextLink;
          free(currentlink);
        }
        templink=templink->nextLink;
      }
      temp1=temp1->nextVertex;
    }
    return 1;
  }
}

//linked list fuctions

stackType createStack()
{
    stackType s;
    s.countt = 0;
    s.top = NULL;
    return s;
}

_Bool push(vertexNd *ip_data, stackType *s1)
{
   snode *newDatanode = ( snode *)malloc(1*sizeof(snode));
   if (newDatanode == NULL)
   {
       return false;
   }
   else
   {
       newDatanode -> data = ip_data;
       /*if (s1->top == NULL) //case of push is an empty stack
       {

           newDatanode->next = NULL;
           s1->top = newDatanode;
           s1->count++;
       }
       else  //in the case of a non empty stack
       {
           s1->top = newDatanode;
           s1->count++;  //since this is same for both the conditions we can move it out
           newDatanode->next = s1->top; // this line applies to both the conditions so we can remove it

       }*/
       newDatanode->next = s1->top; // this line is a replacement to the commented if else block
       s1->top = newDatanode;
       s1->countt++;
       return true;
   }
}

vertexNd * pop(stackType *s1)
{
    snode * temp = s1->top;
    /*if (s1->top->next == NULL)
    {
        s1->top = s1->top->next;
    }
    else
    {
        s1->top = s1->top->next;

    }*/
    s1->top = s1->top->next; //replacement for the commented if else
    vertexNd * poppedEle = temp->data;
    free(temp);
    s1->countt--;
    return poppedEle;
}

void destroystack(stackType *s1) {
    snode *temp;
    while(s1->top != NULL) {
        temp = s1->top;
        s1->top = temp->next;
        free(temp) ;
        s1->countt--;
    }
}


//dfs 

void dfs(graphNd *graph)
{
  //step 1: if graph is empty then return
  if (graph->firstVertex==NULL)
  {
    printf("the graph is empty");
    return;
  }
  //step 2: marking all proccessed flags to 
  vertexNd *temp2 = graph->firstVertex;
  while(temp2!=NULL)
  {
    temp2->processed=0;
    temp2=temp2->nextVertex;
  }

  //step 3: creating a stack
  stackType s = createStack();
  
  //step 4:  for each vertex "vertex A" in the vertex list
  vertexNd *temp;
  temp=graph->firstVertex;
  while(temp!=NULL)
  {

    //a) if vertex A is not processed and vertex A is not in the stack, 
    if(temp->processed==0)
    {
      //push vertex A in the stack
      push(temp, &s);
      //mark processsed flag of vertex A to 1
      temp->processed=1;
    }

    //b) for each vertex B on stack top,
    while(!isEmptystack(s))
    {
      //vertex B = pop stack
      vertexNd *vertexB=pop(&s);
      //process vertex B(print it)
      printf("\n %s", vertexB->name);
      //mark proccessed flag of vertex B to 2
      vertexB->processed=2;
      
      /*push all vertices from the adj list of vertex V which are not processed and which are not in the stack and mark them as in the stack (i.e processed = 1)*/
      linkNd *templinknode=vertexB->firstLink;
      while(templinknode!=NULL)
      {
        if(templinknode->destination->processed==0)
        {
          push(templinknode->destination, &s);
          templinknode->destination->processed=1;
        }
        templinknode=templinknode->nextLink;
      }
    }
    temp=temp->nextVertex;
  }
  //step 5: destroy the stack.
  destroystack(&s);
}

//Breadth first search(BFS)
void bfs(graphNd *graph)
{
  //step1: if the graph is empty return 
  if (graph->firstVertex==NULL)
  {
    printf("\nthe graph is empty");
    return;
  }

  //step2: for each vertex in the vertex list, set processed to 0
  vertexNd *temp = graph->firstVertex;
  while(temp!=NULL)
  {
    temp->processed=0;
    temp=temp->nextVertex;
  }

  //step3: create a queue
  queueType q = createqueue();

  //step4: for each vertex "vertexA" in the vertex list
  vertexNd *temp1 = graph->firstVertex;
  while(temp1!=NULL)
  {
    //a) if vertex A is not processed and is not in the queue
    if(temp1->processed==0)
    {
      //enqueue vertex A
      enqueue(temp1, &q);
      //mark vertex A as in the queue(processed = 1)
      temp1->processed=1;
    }

    //b) for each vertex at queue front 
    while(!isEmpty(q))
    {
      //vertex B = dequeue
      vertexNd *vertexB= dequeue(&q);
      //process vertexB
      printf("\n %s", vertexB->name);
      //mark processed vertex B to 2
      vertexB->processed=2;
      /*enqueue all verteces from the adj list of vertex B which are not
      prcessed andn which are not in the queue. also mark such verteices as in the queue (i.e processed = 1)*/
      linkNd *templinknd = vertexB->firstLink;
      while(templinknd!=NULL)
      {
        if(templinknd->destination->processed==0)
        {
          //enqueue
          enqueue(templinknd->destination, &q);
          //mark processed = 1
          templinknd->destination->processed=1;
        }
        templinknd=templinknd->nextLink;
      }
    }

    temp1=temp1->nextVertex;
  }
  //step 5: destroy the queue.
  destroyqueue(&q);
}