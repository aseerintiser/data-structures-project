#include "AINbst.h"
#include "AINheap.h"

int main()
{
    //TESTING BST
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


    //TESTING MAX HEAP
    int H[]= {0,10,20,30,25,5,40,35}; //Heap: 40 25 35 10 5 20 30
    int i;

    for(i=2; i<=7; i++)
        MXHheapPush(H,i);

    MXHtraverse(H);

    printf("Heap size is %d\n",MXHheapSize(H));

    //After Deleting
    printf("Deleted value is %d\n",MXHheapPop(H,7));

    MXHtraverse(H);

    //For Heap Sort
    for(i=7;i>1;i--)
    {
        MXHheapPop(H,i);
    }

    MXHtraverse(H);


    //TEST DLL
    struct node *ptr;
    struct node *start=NULL; //will point the first node of linked list
    DLLaddFirst(&start,10);
    DLLaddLast($start,&20);
    ptr = DLLfind(&start,ptr,30);
    DLLinsertAfter(&start,ptr,30);

    return 0;
}
