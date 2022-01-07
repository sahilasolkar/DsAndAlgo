/*AUTHOR : SAHIL.A 2107
PROGRAM: HEAP. lib implementation.
DATE CREATED: 5TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "2107_heap.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void reheapup(int heap[],int *count)
{
    while(count>0)
    {
      int parent = (*count-1)/2;
      if(heap[parent]<heap[*count])
      {
        swap(&heap[parent], &heap[*count]);
        *count=parent;
      }
      else 
      {
        break;
      }
    }
}

int insertElement(int heap[], int *size, int val)
{
  heap[*size]=val;
  int i = *size;
  reheapup(heap,&i);
  *size=*size+1;
  return *size;
}

void display(int heap[], int size)
{
  for(int i=0;i<size;i++)
  {
    printf("\n %d", heap[i]);
  }
}

int delete(int heap[], int *size)
{
  int value;		
	if((*size) == 1)
	{
		value = heap[0];
    //free(heap);
    *size=*size-1;
	}
	else
	{
		value = heap[0];
		heap[0] = heap[(*size)-1];
		heap[(*size)-1] = value;
		(*size) = (*size)-1;
		reheapdown(heap, *size, 0);
	}
	return value;
}

void reheapdown(int heap[], int size, int pos)
{
	int largest = pos;		
	int leftchild = 2*pos+1;			
	int rightchild = 2*pos+2;			
	if(leftchild<size && heap[leftchild]>heap[largest])	// to check if leftchild child is larger than root
		largest=leftchild;
	if(rightchild<size && heap[rightchild]>heap[largest])	//to check if rightchild child is larger than root
		largest=rightchild;	
	if(largest != pos)			
	{
		swap(&heap[pos], &heap[largest]);
		reheapdown(heap, size, largest);
	}	
}

void construct(int arr[], int construct[], int n)
{
  int i, j, ct=0;
  for(i=0;i<n;i++)
  {
    insertElement(construct, &ct, arr[i]);
  }

  printf("\n<= the array you entered =>\n");
  for(j=0;j<n;j++)
  {
    printf("\n%d\n", arr[j]);
  }

  printf("\n<= newly constructed heap =>\n");
  for(j=0;j<n;j++)
  {
    printf("\n%d\n", construct[j]);
  }
}

void sort(int heap[], int size)
{
  int i, j, truesize=size-1;
  for(i=0;i<size;i++)
  {
    swap(&heap[0], &heap[truesize]);
    reheapdown(heap, truesize, 0);
    truesize--;
  }
  printf("\n<== SORTED ARRAY ==>\n");
  for(j=0;j<size;j++)
  {
    printf("\n %d\n", heap[j]);
  }
}