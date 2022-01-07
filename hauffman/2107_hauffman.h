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

struct MinHeap {
	int size;
	int capacity;
	struct MinHeapNode** array;
};

struct MinHeapNode {
	char data;
	int freq;
	struct MinHeapNode *left, *right;
};
/*
newNode
parameter = char, int 
fn        = makes a new node and sets the data and freq values
pre cond  = none
output    = *minHeapNode
post cond = newnode is created
*/
struct MinHeapNode* newNode(char data, int freq);
/*
createMinHeap
parameter = int
fn        = a minHeap of a given capacity is created
pre cond  = none
output    = *minHeap
post cond = a minHeap of given capacity is created
*/
struct MinHeap* createMinHeap(int capacity);
/*
swapMinHeapNode
parameter = **MinHeapNode, **MinHeapNode
fn        = swaps the given nodes
pre cond  = the given nodes exist
output    = none
post cond = the given nodes are swaped
*/
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
/*
minHeapify
parameter = *MinHeap, int
fn        = puts the top element in the correct 
            position in the heap
pre cond  = heap is not empty
output    = none
post cond = the top element is correctly placed 
            in the heap.
*/
void minHeapify(struct MinHeap* minHeap, int idx);
/*
isSizeOne
parameter = *MinHeap
fn        = tells if the size is one
pre cond  = heap exist
output    = int
post cond = none
*/
int isSizeOne(struct MinHeap* minHeap);
/*
extractMin
parameter = *MinHeap
fn        = extracts the node with the minimum 
            freqency from the heap
pre cond  = heap is not empty
output    = *MinHeapNode
post cond = none
*/
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
/*
insertMinHeap
parameter = *MinHeap, *MinHeapNode
fn        = inserts the given node to the correct position 
            in the heap
pre cond  = none
output    = *MinHeapNode
post cond = given node is inserted to the correct position in 
            heap
*/
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);
/*
buildMinHeap
parameter = *MinHeap
fn        = builds a minheap from the given heap
pre cond  = heap is not empty
output    = none
post cond = heap is made a minheap
*/
void buildMinHeap(struct MinHeap* minHeap);
/*
printArr
parameter = int[], int
fn        = prints the given array
pre cond  = array is not empty
output    = none
post cond = the given array is printed
*/
void printArr(int arr[], int n);
/*
isLeaf
parameter = *MinHeapNode
fn        = tells if the given node is a root
pre cond  = none
output    = int
post cond = none
*/
int isLeaf(struct MinHeapNode* root);
/*
createAndBuildMinHeap
parameter = char[], int[], int
fn        = creates a minheap of the given capacity 
            and inserts the given data and freqency
            into the nodes of the minheap
pre cond  = none
output    = *MinHeap
post cond = a minheap of capacity created and the 
            data and freq are inserted
*/
struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size);
/*
buildHuffmanTree
parameter = char[], int[], int
fn        = builds a hauffman tree using a minheap
pre cond  = none
output    = *minHeapNode
post cond = a hauffman tree is created
*/
struct MinHeapNode* buildHuffmanTree(char data[],int freq[], int size);
/*
printCodes 
parameter = *minHeapNode, int[], int 
fn        = prints the codes of the characters
pre cond  = data and freq are not empty
output    = none
post cond = codes of the characters are printed 
*/
void printCodes(struct MinHeapNode* root, int arr[], int top);
/*
HuffmanCodes
parameter = char[], int[], int
fn        = builds a hauffman tree and prints 
            the codes for each character
pre cond  = none
output    = none
post cond = characters with codes are printed
*/
void HuffmanCodes(char data[], int freq[], int size);
#endif