/*AUTHOR : SAHIL.A 2107
PROGRAM: HAUFFMAN CODE. main.
DATE CREATED: 5TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "2107_hauffman.h"

int main()
{
  int size, freq[50];
  char arr[50];
  printf("enter the total number of elements");
  scanf("%d", &size);
  for(int i =0;i<size;i++)
  {
    printf("enter the character");
    scanf("%s", &arr[i]);
    printf("enter the frequency of %c ", arr[i]);
    scanf("%d", &freq[i]);
  }
	HuffmanCodes(arr, freq, size);
	return 0;
}