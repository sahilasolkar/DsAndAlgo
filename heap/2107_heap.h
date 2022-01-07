/*AUTHOR : SAHIL.A 2107
PROGRAM: HAUFFMAN CODE. lib header file.
DATE CREATED: 5TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER
#ifndef _bst_H
#define _bst_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int heap[50];

/*
swap
parameter = *int, *int
fn        = swaps the two elemets
pre cond  = none
output    = none
post cond = elements x and y are swapped
*/
void swap(int *x, int *y);
/*
reheapup
parameter = int[], *int 
fn        = compares the inserted element with its parent and
            swaps if the parent is smaller
pre cond  = heap is not empty
output    = none
post cond = the element is placed correctly in the heap
*/
void reheapup(int heap[],int *count);
/*
insert element
parameter = int[], *int
fn        = inserts an element to the correct place in the heap
pre cond  = none
output    = int
post cond = element correctly inserted into the heap
*/
int insertElement(int heap[], int *size, int val);
/*
display
parameter = int[], int
fn        = displays the array provided
pre cond  = none
output    = none
post cond = array is printed
*/
void display(int heap[], int size);
/*
reheapdown
parameter = int[], int , int
fn        = puts the top element in the correct 
            position in the heap
pre cond  = heap is not empty
output    = none
post cond = the top element is correctly placed 
            in the heap.
*/
void reheapdown(int heap[], int size, int pos);
/*
delete
parameter = int[], *int
fn        = deletes the root value of the heap.
pre cond  = heap is not empty
output    = int 
post cond = root is deleted and the heap is organised
*/
int delete(int heap[], int *size);
/*
construct
parameter = int[], int[], int 
fn        = constructs a heap from a given array
pre cond  = array is not empty
output    = none
post cond = heap is constructed from the array
*/
void construct(int arr[], int construct[], int n);
/*
sort
parameter = int[], int
fn        = sorts the elements of a heap
pre cond  = heap is not empty
output    = none
post cond = elements in the heap are sorted
*/
void sort(int heap[], int size);

#endif