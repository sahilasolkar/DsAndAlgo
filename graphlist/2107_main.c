/*
AUTHOR : SAHIL.A
PROGRAM: GRAPH USING ADJACENCY LIST. MAIN.
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2107_graph.h"
#include "2107_queue.h"


int main()
{
    printf("\n ========== GRAPH ========== \n \n ");

    int choice, check;

    char val[20], src[20], dest[20];

    graphNd * graphA = createGraph();

    do
    {
        printf("\n **** MENUE **** : \n \n 1==> INSERT ELEMENT \n 2==> INSERT EDGE \n 3==> DELETE VERTEX \n 4==> DFS \n 5==> BFS \n");
        scanf("%d", &choice);
        switch(choice)
        {
          case 1: //insert a vertex
          printf("enter the vertex name");
          scanf("%s", val);
          int checkval = insert(graphA, val);
          if(checkval==1)
          {
            printf("insertion of => %s <= was successful", val);
          }
          else
          {
            printf("couldnt insert %s - memory overflow", val);
          }
          break;

          case 2: //insert an edge
          printf("enter the source of the edge ");
          scanf("%s", src);
          printf("enter the destination of the edge ");
          scanf("%s", dest);
          check = insertEdge(graphA, src, dest);
          if (check == -2)
          {
            printf("the source => %s <= was not found", src);
          }
          else if (check == -3)
          {
            printf("the destination => %s <= was not found", dest);
          }
          else if (check == -1)
          {
            printf("memory overflow");
          }
          else if (check == 1)
          {
            printf("An edge was successfully created from %s to %s", src, dest);
          }
          break;

          case 3: //delete vertex
          printf("enter the element you want to delete");
          scanf("%s", val);
          check = deleteVertex(graphA, val);
          if (check==-1)
          {
            printf("couldn't  find the vertex => %s", val);
          }
          else if (check==-2)
          {
            printf("cannot delete. The vertex has links");
          }
          else 
          {
            printf("the vertex => %s <= is deleted successfully", val);
          }
          break;

          case 4: //dfs
          dfs(graphA);
          break;

          case 5: //bfs
          bfs(graphA);
          break;

          case 6: //exit
          break;

          default: printf("\n you have entered a wrong option");
          break;
        
        }
        
    }while(choice !=6);
    

    return 0;
}
