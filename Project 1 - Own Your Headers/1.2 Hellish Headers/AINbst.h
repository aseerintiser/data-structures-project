#ifndef AINbst
#define AINbst

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _STDIO_H_
#include <stdio.h>
#endif

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL; //root is globally accessible

//Inserts a node
void BSTinsert(int key);
//Checks if key exists in BST
struct Node * BSTfind(int key);
//Finds the minimum value stored in BST
int BSTfindMin(struct Node *p);
//Finds the maximum value stored in BST
int BSTfindMax(struct Node *p);
//Finds the successor(leftmost child of right subtree)
struct Node *BSTnextLarger(struct Node *p);
//Deletes the node containing the value key
struct Node *BSTdelete(struct Node *p,int key);

#endif
