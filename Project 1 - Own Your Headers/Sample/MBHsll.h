#ifndef _MBH_SLL_H_
#define _MBH_SLL_H_

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STDIO_H_
#include <stdio.h>
#endif

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

typedef struct SinglyLinkedList node;
#define sll node

// Creates a new node that contains the value x and points to n.
node *SLLcreateNode(int val, node *n);
// Adds a new node containing value  x to the front of the linked list
node *SLLaddFirst(node *head, int val);
// Adds a new node containing value x to the end of the linked list
node *SLLaddLast(node *head, int val);
// Finds the node containing k and insert a new node containing value v after it
node *SLLinsertAfter(node *head, int key, int val);
// Finds the node containing k and insert a new node containing value v before it
node *SLLinsertBefore(node *head, int key, int val);
// Finds the node containing k and deletes it
node *SLLdelete(node *head, int key);
// Traverse the linked list
void SLLtraverse(node *head);
#endif
