/*AUTHOR : SAHIL.A 2107
PROGRAM: GRAPH USING ADJACENCY LIST.
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include"2107_graph.h"
#include<stdlib.h>
#include <string.h>
#include "2107_stack.h"
#include "2107_queue.h"

//create graph fn 
graphNd * creategraph(int count)
{
  int i,j,p;
  char a;
  //allocate memory for the graphnode
  graphNd *newgraph = (graphNd *)malloc(sizeof(graphNd));
  newgraph->vertexCount=count;
  //dynamically allocating memory
  newgraph->vertexVector = (char *)malloc(count * sizeof(char));
  if(newgraph)
  {
    //making the matrix
    newgraph->adjMatrix = (int **) malloc(count*sizeof(int *)); 
    for(i=0;i<count;i++)
    {
      //newgraph->vertexVector[i] = ' ';
      newgraph->adjMatrix[i] = (int *) malloc(count*sizeof(int)); 
    } 
	  
    //printing 2d array(testing purpose)
    for(i=0;i<count;i++){ 
      for(j=0;j<count;j++)
      { 
		    //p[i][j] = i+j; 
		    printf("%d ",newgraph->adjMatrix[i][j]); 
	    } 
	    printf("\n"); 
    }


  }
  if(!newgraph)
  {
    printf("the graph couldnot be created");
    return NULL;
  }

  return newgraph;
}

void readvertices(graphNd *newgraph, int count)
{
    //make an array to hold the vertices
    //char arr[count];
    for (int i=0;i<count;i++)
    {
      printf("enter the name for value %d", i);
      scanf("%s", &newgraph->vertexVector[i] );
    }
    //this printing is for testing purpose
    printf("matrix %d X %d created", count,count);
    for(int i=0; i<count; i++)
    {
      printf("\nvalue: %c", newgraph->vertexVector[i]);
    }
    printf("\n");

    return;
}

//fn to insert an edge between the src node and the destination node
//return 1: success
//return -1: source doesnt exist
//return -2: destination doesnt exist
int insertEdge(graphNd *newgraph, char srcName, char destName)
{
    int success = -2, count = 0, src, dest;
    while(count < newgraph->vertexCount){
        if(newgraph->vertexVector[count] == srcName){
            success = -1;
            src = count;
            break;
        }
        count++;
    }
    if(success == -1){
        count = 0;
        while(count < newgraph->vertexCount){
            if(newgraph->vertexVector[count] == destName){
                success = 1;
                dest = count;
                break;
            }
            count++;
        }
        if(success == 1){
            newgraph->adjMatrix[src][dest] = 1;
            return(1); //Added new edge
        }
        return(-2); //Destination not found
    }
    return(-1); //Source not found
}

/*fn to locate the presence of the given two vertices
if the graph is empty return -3
if vertex is not present then it returns -1 
*/
int locate(graphNd *newgraph, char a[])
{
  //check if the graph is empty, return -3 if empty
  if(newgraph->vertexCount!=0)
  {
  for(int i=0;i<newgraph->vertexCount;i++)
  {
    if(strcmp(&newgraph->vertexVector[i],a)==0)
    {
      return i;
    }
  }
  }
  return -1;
}

/*fn to display the matrix provided
*/
void displayMatrix(graphNd * newgraph)
{
  for(int i=0;i<newgraph->vertexCount;i++){ 
      for(int j=0;j<newgraph->vertexCount;j++)
      { 
		    //p[i][j] = i+j; 
		    printf("%d ",newgraph->adjMatrix[i][j]); 
	    } 
	    printf("\n"); 
    }
}

//depth first search 
void DFS(graphNd *graph)
{
    stackType s;
    int count = 0, i, j;
    int processed[20];
    char pop;
    //step 2: marking all proccessed flags to zero
    for(count = 0; count < graph->vertexCount; count++)
        processed[count] = 0;
    count = 0;
    //step 3: create a stack
    s = stackCreate();
    //step 4: for each vertex, vertex A in the vertex list
    while(count < graph->vertexCount){
      //a) if vertex A is not processed and vertex A is not in the stack 
        if (processed[count] == 0){
            //push vertex A i nthe stack
            stackPush(graph->vertexVector[count], &s);
            //mark processed of vertex A to 1
            processed[count] = 1;
        }
    //b)for each vertex B on stack top
        while(stackIsEmpty(s) == false){
            //pop
            pop = stackPop(&s);
            //process vertex B (print it)
            printf("\n%c", pop);
            for(i = 0; i < graph->vertexCount; i++)
                if(graph->vertexVector[i] == pop)
                    break;
            //mark processed of vertex B to 2
            processed[i] = 2;
            /* push all vertices from the adj list of vertex B which are not processed and which are not in the stack and mark them as in the stack(i.e processed = 1)
            */
            for(j = 0; j < graph->vertexCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0){
                        stackPush(graph->vertexVector[j], &s);
                        processed[j] = 1;
                    }
        }
        count++;
    }
    //step 5: destroy the stack
    stackDelete(&s);
}

//breadth first search
void BFS(graphNd *graph)
{
    queueType q;
    int count = 0, i, j;
    int processed[20];
    char deq;
    //step 2: mark all the processed to zero
    for(count = 0; count < graph->vertexCount; count++)
        processed[count] = 0;
    count = 0;
    //step 3: create a queue
    q =createqueue();
    //step 4: for each vertex, vertex A in the vertex list 
    while(count < graph->vertexCount){
      //a) if the vertex A is not processed and is not int eh queue
        if(processed[count] == 0){
          //enqueue the vertex in the queue
            enqueue(graph->vertexVector[count], &q);
            //mark the processed to 1
            processed[count] = 1;
        }
        //b) for each vertex at the queue front
        while(isEmpty(q) == false){
          //dequeue 
            deq = dequeue(&q);
            //print
            printf("\n%c", deq);
            //search for the dequeued vertex in the matrix
            for(i = 0; i < graph->vertexCount; i++)
                if(graph->vertexVector[i] == deq)
                    break;
            //mark the processed = 2
            processed[i] = 2;
            /* enqueue all the vertices from the adj list o fthe vertex B which are not processed and which are not in the queue. Also mark such vertices as in the queue(i.e proceeded =1 )
            */
            for(j = 0; j < graph->vertexCount; j++)
                if(graph->adjMatrix[i][j] == 1)
                    if(processed[j] == 0){
                        enqueue(graph->vertexVector[j], &q);
                        processed[j] = 1;
                    }
        }
        count++;
    }
    //step 5: destroy the queue
    destroyqueue(&q);
}