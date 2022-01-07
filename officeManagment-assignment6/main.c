
/*
AUTHOR : SAHIL.A
PROGRAM: queue USING LINKED LIST
DATE CREATED: 3rd OCT 2021
DATE MODIFIED: 6th OCT 2021
*/
// DS DEVELOPER


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "queue.h"

int main()
{
    printf("\n QUEUE USING LINKEDLIST \n \n ");

    int choice; //size;
    int budget, dequeueped_ele, peeked_ele;
    int clnm;
    //size = 5;
    queueType home = createqueue();
    queueType shop = createqueue();
    queueType CompShop = createqueue();
    queueType CompHome = createqueue();



    do
    {
        printf("\n MENUE : \n \n 1==>add new offer to shop renovation \n 2==>add new offer to home renovation \n 3==>mark home renovation offer complete \n 4==>mark shop renovation complete \n 5==>display home renovation offers \n 6==>display shop renovation offers \n 7==>display completed home renovation offers \n 8==>display completed shop renovation offers \n 9==>display total profit earned \n 10==>EXIT");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: //add new offer to shop ren
            if (!isFull(shop))
            {
            printf("\n enter the name of the client");
            scanf("%d", &clnm);
            printf("\n enter the budget of the client");
            scanf("%d", &budget);
            //printf("\n enter the deadline of the project");
            //scanf("%s", deadline);

            enqueue(clnm, budget, &shop);
            }
            else
            {
                printf("\n no offers");
            }
            break;

        case 2: //add new offer to home ren

            if (!isFull(home))
            {
            printf("\n enter the name of the client");
            scanf("%d", &clnm);
            printf("\n enter the budget of the client");
            scanf("%d", &budget);
            //printf("\n enter the deadline of the project");
            //scanf("%s", deadline);

            enqueue(clnm, budget, &home);
            }
            else
            {
                printf("\n no offers");
            }
            break;

        case 3: //mark home renovation offer complete

            if (!isEmpty(home))
            {
              int f,as;
              printf("enter the fees for the project");
              scanf("%d",&f);
              printf("enter the total amount spent for the project");
              scanf("%d",&as);
              complete(f, as, &home, &CompHome);
            }
            else
            {
                printf("\n no offers");
            }
            break;


          case 4: //mark shop renovation complete
            if (!isEmpty(shop))
            {
              int f,as;
              printf("enter the fees for the project");
              scanf("%d",&f);
              printf("enter the total amount spent for the project");
              scanf("%d",&as);
              complete(f, as, &shop, &CompShop);
            }
            else
            {
               printf("\n no offers");
               
            }
            break;

          case 5: //display home renovation offers
            if (!isEmpty(home))
            {
              Display(home);
            }
            else
            {
              printf("\n no offers");
            }
            break;

          case 6: //display shop renovation offers
            if (!isEmpty(shop))
            {
              Display(shop);
            }
            else
            {
              printf("\n no offers");
            }
            break;
          
          case 7: //display completed home renovation offers
            if (!isEmpty(CompHome))
            {
              DisplayComplete(CompHome);
            }
            else
            {
              printf("\n no offers");
            }
            break;
          
          case 8: //display completed shop renovation offers
            if (!isEmpty(CompShop))
            {
              DisplayComplete(CompShop);
            }
            else
            {
              printf("\n no offers");
            }
            break;

          case 9: 


            profitearned(CompHome, CompShop);
            



            
            break;



            

        case 10: //Exit
            break;

        default: printf("\n you have entered a wrong option");

        }
    }while(choice !=10);
    destroyqueue(&home);
    destroyqueue(&shop);
    destroyqueue(&CompShop);
    destroyqueue(&CompShop);

    return 0;
}
