/*
AUTHOR : SAHIL.A 2107
PROGRAM: GRAPH USING ADJACENCY LIST. MAIN.
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2107_graph.h"
#include "2107_stack.h"
#include "2107_queue.h"

int main()
{
  int n,foundsrc, founddest;
  char src, dest;
  printf("\n ========== GRAPH ========== \n \n ");
  int choice;
  printf("\nenter the number of vertices");
  scanf("\n%d", &n);
  graphNd *newgraph = creategraph(n);
  printf("\n%d", newgraph->vertexCount);
  do
    {
        printf("\n **** MENUE **** : \n \n 1==> READ VERTICES \n 2==> READ EDGE \n 3==> REMOVE EDGE \n 4==> DFS \n 5==> BFS \n 6=> DISPLAY MATRIX \n 7=> EXIT \n");
        scanf("%d", &choice);
        switch(choice)
        {
          //read VERTICES
          case 1:
          readvertices(newgraph, n);
          break;

          //read edges
          case 2:
          printf("enter the source vertex");
          scanf("%s",&src);
          printf("enter the destination vertex");
          scanf("%s",&dest);
          int p;
          p=insertEdge(newgraph, src, dest);
          if(p == 1)
                    printf("\nNew edge added in the matrix.");
                    
                else if(p == -1)
                    printf("\nSource vertex could not be found. \nEnter valid input. \nTry again.");
                else if(p == -2)
                    printf("\nDestination vertex could not be found. \nEnter valid input. \nTry again.");
                break;
          break;

          case 4:
          DFS(newgraph);
          break;

          case 5:
          BFS(newgraph);
          break;

          case 6:
          displayMatrix(newgraph);
          break;
        }
    
    }while(choice!=7);
}