#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

//Adds a new node containing value x to the front of the linked list
void DLLaddFirst(struct node **s, int data)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->info = data;
    p->prev = NULL;
    p->next = *s; //Start's value is in next
                  //If list is empty, NULL in start
                  //If not empty, the first node's address will come to next
    *s=p; //Now new created node's address is in start
}

//Adds a new node containing data to the end of the linked list
void DLLaddLast(struct node **s, int data) //s is already a pointer, pointing a pointer, so **s
{
    struct node *p,*t; //p is for new node, t is for pointing second last node's next address to last node's previous address
    p=(struct node*)malloc(sizeof(struct node));
    p->info = data;
    p->next = NULL;

    if(*s==NULL) //when list is empty
    {
        p->prev=NULL;
        *s=p;
    }
    else
    {
        t=*s; //t is pointing the first node
        while(t->next!=NULL) //if t->next==NULL, then it's last node
            t=t->next; //It will continue to traverse till last node
        p->prev=t; //last node's address should be kept in new node's previous
        t->next=p; //new node's address should be kept in last node's address
    }
}

//Finds a node and inserts a new node containing data after it
void DLLinsertAfter(struct node **s,struct node **ptr, int data) //ptr is for after which node we want to insert
{
    struct node *p;
    if(ptr==NULL)
        printf("Invalid insertion");
    else
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->info = data;
        p->prev = ptr; //ptr e jetar pore rakhte chai, shetar address rakha
        p->next = ptr->next; //ptr->next e 3rd node tar address rakha
        if(ptr->next!=NULL)
            ptr->next->prev = p; //3rd node tar previous e new node tar address rakhlam
        ptr->next = p; //New node's address assigned to ptr->next
    }
}

//Finds the node containing data
struct node* DLLfind(struct node **s, int data)
{
    struct node *t;
    if(*s==NULL) //Is linked list empty?
        return NULL;
    else{
        t=*s; //s pointing start, now t also pointing start
        while(t!=NULL){ //searching whole list
            if(t->info==data)
                return(t);
            t=t->next; //If the desired data is not in t->info, it will point to the next node.
        }
        return(NULL); //While breaks, we have not got any value
    }
}

//Finds the node containing k and deletes it
int DLLdelete(struct node **s,struct node *ptr) //ptr pointing the node we want to delete
{
    if(*s==NULL)
        return 0;
    if(ptr->prev==NULL){ //If the node to delete is the first node
        *s = ptr->next; //2nd node's address sent to start
        free(ptr); //safely remove
        return(1);
    }
    if(ptr->next==NULL){ //If there is no 4th node, the node to delete is the last
        ptr->prev->next = ptr->next;
        free(ptr);
        return(1); //as successfully deleted, so 1
    }
    ptr->prev->next = ptr->next; //2nd node's next (ptr->prev->next) will point 4th node's previous denoted by ptr->next (let delete 3rd node)
    ptr->next->prev = ptr->prev; //4th node's previous(ptr->next->prev) will point 2nd node
    free(ptr); //safely remove the ptr node
    return(1);
}

//Traverse the linked list sequentially and print the data
void DLLtraverse(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("List is empty");
    else {
        t = *s;
        while(t!=NULL){
            printf("%d ",t->info);
            t=t->next;
        }
    }
}


main()
{
    struct node *ptr;
    struct node *start=NULL; //will point the first node of linked list
    DLLaddFirst(&start,10);
    DLLaddLast($start,&20);
    ptr = DLLfind(&start,ptr,30);
    DLLinsertAfter(&start,ptr,30);


}

