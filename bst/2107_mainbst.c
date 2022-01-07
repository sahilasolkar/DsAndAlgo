
/*
AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST
DATE CREATED: 22th SEPT 2021
DATE MODIFIED: 7th NOV 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "2107_bst.h"


int main()
{
    printf("\n BINARY SEARCH TREE \n \n ");

    int choice;

    bst_tree * tree_A = BST_create();
    int data, dltkey;


    do
    {
        printf("\n MENUE : \n \n 1==> INSERT ELEMENT \n 2==> INORDER TRAVERSAL \n 3==> DELETION \n 4==> DESTROY \n 5==> SEARCH \n 6==> EXIT \n");
        scanf("%d", &choice);
        switch(choice)
        {
          case 1:
          printf("enter the element you want to insert");
          scanf("%d", &data);
          BST_insert(tree_A, data);

          printf("data inserted!");
          
          break;
          
          case 2:
          if (tree_A->root == NULL)
            {
              printf("the tree is empty ");



            }
          else
          {
            BST_traversal(tree_A);
          }
          

          break;

          case 3:

          if (tree_A==NULL)
          {
            printf("tree not created");
          }

          else 
          {
            if (tree_A->root == NULL)
            {
              printf("the tree is empty ");



            }
            else 
            {
              printf("enter the data to be delted");
              scanf("%d", &data);
              //printf("reached1");
              if (BST_Delete(tree_A, data)==true)
              {
                printf("the data is deleted");
              }
              else
              {
                printf("data not found in the tree");
              }
            }
          }
          
          break;

          case 4:

          if(tree_A==NULL)
          {
            printf("tree not created");
          }
          else if (tree_A->root == NULL)
          {
            
            printf("the tree is empty ");

          }
          else
          {
            bst_destroy(tree_A);
          }
          break;

          case 5:
          
          if(!isEmpty(tree_A)){     
                    printf("Enter The key to be Searched\n");
                    scanf("%d",&data);
                    if(searchtree(tree_A->root,data)){
                        printf("\nSearch Successfull\n");
                    }
                    else{
                        printf("\nelement not found\n");
                        }
                }
                else
                    printf("\nTree is empty!!\n");  
          break;



          

          case 6:
            break;

          default: printf("\n you have entered a wrong option");
        
        }
        
    }while(choice !=6);
    

    return 0;
}
