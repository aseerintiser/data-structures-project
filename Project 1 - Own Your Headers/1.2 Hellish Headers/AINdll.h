#ifndef AINdll
#define AINdll

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STDIO_H_
#include <stdio.h>
#endif

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

//Adds a new node containing value x to the front of the linked list
void DLLaddFirst(struct node **s, int data);
//Adds a new node containing data to the end of the linked list
void DLLaddLast(struct node **s, int data); //s is already a pointer, pointing a pointer, so **s
//Finds a node and inserts a new node containing data after it
void DLLinsertAfter(struct node **s,struct node **ptr, int data); //ptr is for after which node we want to insert
//Finds the node containing data
struct node* DLLfind(struct node **s, int data);
//Finds the node containing k and deletes it
int DLLdelete(struct node **s,struct node *ptr); //ptr pointing the node we want to delete
//Traverse the linked list sequentially and print the data
void DLLtraverse(struct node **s);
#endif

