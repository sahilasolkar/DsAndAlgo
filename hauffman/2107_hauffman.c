/*AUTHOR : SAHIL.A 2107
PROGRAM: HAUFFMAN CODE. lib implementation.
DATE CREATED: 5TH JAN 2022
DATE MODIFIED: 5th JAN 2022
*/
// DS DEVELOPER

#include <stdio.h>
#include <stdlib.h>
#include "2107_hauffman.h"

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, int freq)
{
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

// a min heap of given capacity
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	// current size is 0
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(
		minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

//minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (left < minHeap->size
		&& minHeap->array[left]->freq
			< minHeap->array[smallest]->freq)
		smallest = left;
	if (right < minHeap->size
		&& minHeap->array[right]->freq
			< minHeap->array[smallest]->freq)
		smallest = right;
	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size == 1);
}

//extracts minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) 
  {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

//fu to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

//print an array of size n
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);

	printf("\n");
}

//check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[],int freq[], int size)
{
  //create a new minheap node of the provided size
	struct MinHeap* minHeap = createMinHeap(size);
  //insert the array elements into the minheap
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
  //make the size  = provided size
  minHeap->size = size;
  //this makes it a heap
	buildMinHeap(minHeap);
	return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[],int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	// Step 1: Create a min heap of capacity
	// equal to size. Initially, there are
	// modes equal to size.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	// while size of heap doesn't become 1
	while (!isSizeOne(minHeap)) {
		// Step 2: Extract the two minimum
		// freq items from min heap
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		// this node will have freq = sum of freq of the above extracted nodes
		top = newNode('$', left->freq + right->freq);
    //set the top as parent of left and right
		top->left = left;
		top->right = right;
    //insert the new node back to the heap
		insertMinHeap(minHeap, top);
	}
	// Step 4: The remaining node is the root node and the tree is complete.
	return extractMin(minHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
	// Assign 0 to left edge and recur
	if (root->left) 
  {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	// Assign 1 to right edge and recur
	if (root->right) 
  {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	// If this is a leaf node, then
	// it contains one of the input
	// characters, print the character
	// and its code from arr[]
	if (isLeaf(root)) 
  {
		printf("%c: ", root->data);
		printArr(arr, top);
	}
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
	// Construct Huffman Tree
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
  int MAX = 100;
	// Print Huffman codes using
	// the Huffman tree built above
	int arr[MAX], top = 0;
	printCodes(root, arr, top);
}