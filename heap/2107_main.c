/*AUTHOR : SAHIL.A 2107
PROGRAM: HAUFFMAN CODE. main.
DATE CREATED: 5TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "2107_heap.h"

int main()
{
  int choice, value, count=0, temp = 0, len, arr[50], con[50], tem[50];
  do
  {
  printf("\n \n***** H E A P ***** \n");
  printf("\n **** MENUE **** : \n \n 1==> insert element \n 2==> delete element \n 3==> display the heap \n 4==> construct heap from an array \n 5==> sort \n 6==> exit \n");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1:
    printf("enter the value you want to add to the heap\n");
    scanf("%d", &value);
    count=insertElement(heap, &count, value);
    printf("the value %d was successfully added to the heap!", value);
    break;

    case 3:
    printf("\n*** YOUR HEAP *** \n");
    display(heap, count);
    break;

    case 2:
    
    if(count==0)
    {
      printf("there are no elements in the heap!");
      break;
    }
    else
    {
      temp = delete(heap, &count);
      printf("the root => %d was deleted", temp);
      break;
    }

    case 4:
    printf("enter the length of the array");
    scanf("%d", &len);
    for(int k=0;k<len;k++)
    {
      printf("enter the element number %d", k);
      scanf("%d", &arr[k]);
    }
    construct(arr, con, len);
    break;

    case 5:
    printf("\n%d\n", count);
    for (int i = 0; i < count; i++)
    {
      arr[i] = heap[i];
    }
    sort(arr, count);
    break;
  }
  }while(choice!=6);
}



