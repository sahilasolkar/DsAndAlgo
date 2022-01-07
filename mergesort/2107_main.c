/*AUTHOR : SAHIL.A 2107
PROGRAM: MERGESORT. main
DATE CREATED: 5th jan 2022
DATE MODIFIED: 5th jan 2022
*/
// DS DEVELOPER


#include <stdio.h>
#include <stdlib.h>
#include "2107_mergesort.h"

int main()
{
	//int arr[] = { 12, 11, 13, 5, 6, 7 };
  //int arr_size = sizeof(arr) / sizeof(arr[0]);
  int choice, n, con[50], size=0;
  do
  {
  printf("\n ***** MERGESORT ***** \n");
  printf("\n **** MENUE **** : \n \n 1==> create array \n 2==> mergesort \n 3==> display \n 4==> exit \n");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1:
    printf("\nenter the size of the array");
    scanf("%d", &size);
    for(int i=0;i<size;i++)
    {
      printf("\nenter the element number 1: ");
      scanf("%d", &arr[i]);
    }
    printf("\n--YOUR ARRAY--\n\n");
    printArray(arr, size);
    break;
    
    case 2:
    if(size==0)
    {
      printf("the array is empty");
      break;
    }
    mergeSort(arr, 0, size - 1);
    printf("\n--SORTED ARRAY--\n\n");
    printArray(arr, size);
    break;

    case 3:
    printf("\n--ARRAY--\n\n");
    printArray(arr, size);
    break;

  }
  }while(choice!=4);
	return 0;
}
