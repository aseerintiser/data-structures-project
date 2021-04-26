#ifndef AINheap
#define AINheap

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STDIO_H_
#include <stdio.h>
#endif

//Converts an array into a max-heap
void MXHbuildMaxHeap();
//Returns the size of the heap
int MXHheapSize(int A[]);
//Insert a value into the max-heap
void MXHheapPush(int A[], int n); //n is the index of recently stored element
//Extract the max item from the max-heap
int MXHheapPop(int A[], int n); //n last index of array
//Sorts the array using heap sort
void MXHheapSort(int A[], int n); //n last index of array
//Traverse the heap array sequentially and print the keys
void MXHtraverse(int A[]);

#endif
