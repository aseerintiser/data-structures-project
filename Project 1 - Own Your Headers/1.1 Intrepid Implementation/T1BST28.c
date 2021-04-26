#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL; //root is globally accessible

//Inserts a node
void BSTinsert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL,*p; //p is for creating new node
    if(root==NULL) //then this is the first node, so I need to create a new node
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data = key; //p's data will be the key value I want to insert
        p->lchild = p->rchild = NULL; //p's left and right child is null
        root = p; //After creating new node p, root will point on p
        return; //After creating the node, the procedure will stop
    }
    //If root is not null
    while(t!=NULL)
    {
        r=t; //r will be following p, as r is the tale pointer
        if(key < t->data) //if the value to insert is less
            t=t->lchild; //move t pointer upon left child
        else if(key > t->data) //if the value to insert is greater
            t=t->rchild; //move t pointer upon right child
        else
            return;
    }
    //Create a new node p in the pointer position
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild = p->rchild = NULL;
    // Link the node with the BST
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

//Checks if key exists in BST
struct Node * BSTfind(int key) //will return the node where the key value is found
{
    struct Node *t=root; //t pointing root
    while(t!=NULL)
    {
        if(key == t->data)
            return t;
        else if(key < t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL; //If I come out the loop without any key found, simply return null
}

//Finds the minimum value stored in BST
int BSTfindMin(struct Node *p)
{
    while (p->lchild != NULL)
        p = p->lchild; //Moving down to left subtree

    return (p->data);
}

//Finds the maximum value stored in BST
int BSTfindMax(struct Node *p)
{
    while (p->rchild != NULL)
        p = p->rchild; //Moving down to right subtree

    return (p->data);
}

//Finds the successor(leftmost child of right subtree)
struct Node *BSTnextLarger(struct Node *p)
{
    while(p && p->lchild != NULL) //p should not be null and p's left child should not be null
        p=p->lchild; //Will be moving on to left hand side

    return p;
}

//Deletes the node containing the value key
struct Node *BSTdelete(struct Node *p,int key)
{
    struct Node *q;

    if(p==NULL) //Nothing to delete
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL) //p is leaf node
    {
        if(p==root) //if last node is root only
            root=NULL; //Make root null, thus delete it
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->lchild = BSTdelete(p->lchild,key); //Performs search upon left subtree recursively
    else if(key > p->data)
        p->rchild = BSTdelete(p->rchild,key);
    else //Key is found, now delete it
    {
            q = BSTnextLarger(p->rchild); //Finds successor
            p->data = q->data; //Replace successor with p's data
            p->rchild = BSTdelete(p->rchild,q->data); //After replacement the successor q's place is filled up with it's successor again
                                                      //and deleting that successor's previous empty node after copying
    }
    return p;
}

int main()
{
    struct Node *temp; //For taking the result from BSTfind; As BSTfind returns a node
    BSTinsert(50);
    BSTinsert(10);
    BSTinsert(40);
    BSTinsert(20);
    BSTinsert(30);

    printf("\n");

    temp=BSTfind(20);
    if(temp!=NULL)
        printf("Element %d is found\n\n",temp->data);
    else
        printf("Element is not found\n\n");


    printf("Minimum value is %d\n",BSTfindMin(root));
    printf("Maximum value is %d\n\n",BSTfindMax(root));

    printf("[After BSTdelete operation]\n");
    BSTdelete(root,20);

    temp=BSTfind(20);
    if(temp!=NULL)
        printf("Element %d is found\n",temp->data);
    else
        printf("Element is not found\n");


    return 0;
}
