/*AUTHOR : SAHIL.A 2107
PROGRAM: MERGESORT. lib implementation
DATE CREATED: 5th jan 2022
DATE MODIFIED: 5th jan 2022
*/
// DS DEVELOPER


#include<stdio.h>
#include <stdlib.h>
#include "2107_mergesort.h"

//main merge fn 
//to merge two arrays in a sorted manner
void merge(int arr[], int l, int m, int r)
{
  //
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/*
  temperary arrays left and right to store the left.
  values left from mid go to the left array 
  values right from mid go to the right array
  */ 
	int Left[n1], Right[n2];
	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	//Merge the temp arrays back into arr[]
	i = 0; // starting index of first array of left[]
	j = 0; // starting index of second array of right[]
	k = l; // starting index of merged array arr[]
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	/*
  Copy the remaining elements of L[], if there
	are any 
  */
	while (i < n1) {
		arr[k] = Left[i];
		i++;
		k++;
	}

	/* 
  Copy the remaining elements of R[], if there
	are any 
  */
	while (j < n2) {
		arr[k] = Right[j];
		j++;
		k++;
	}
}

/*
takes the lowest and highest index values of the array arr[] 
*/
void mergeSort(int arr[], int l, int r)
{
  //check if low is less than high
	if (l < r) {
		int m = l + (r - l) / 2;
    //merge from low to mid
		mergeSort(arr, l, m);
    //merge from mid to high 
		mergeSort(arr, m + 1, r);
    //compare and mergesort the arrays
		merge(arr, l, m, r);
	}
}

//to display the array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
