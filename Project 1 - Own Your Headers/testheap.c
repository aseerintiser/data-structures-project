#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Converts an array into a max-heap
void MXHbuildMaxHeap(int A[])
{
  //  int A[]= {0,10,20,30,25,5,40,35};
    int i;
    for(i=2; i<=7; i++)
    {
        MXHheapPush(A,i);
    }
}

int MXHheapSize(int A[])
{
    return sizeof(A);
}

//Insert a value into the max-heap
void MXHheapPush(int A[], int n) //n is the index of recently stored element
{
    int temp, i=n;
    temp = A[n];

    while(i>1 && temp>A[i/2]) //A[i/2] is temp's parent
    {
        A[i] = A[i/2]; //copy
        i = i/2; //Bring i to parent and point
    }
    A[i] = temp; //After loop exists, we have the desired position for the element; copy there
}

//Extract the max item from the max-heap
int MXHheapPop(int A[], int n) //n last index of array
{
    int x,i,j,temp,val;
    val=A[1]; //deleted value is taken at val
    x=A[n]; //last element is taken to x
    A[1]=A[n]; //last element is copied to first
    i=1; //i is index 1
    j=2*i; //j is at left child of i
    while(j < n-1) //n-1 is the end of the heap
    {
        if(A[j+1]>A[j]) //compare left and right child, and let j point on greater child
            j=j+1; //if right child greater, j point to right child
        if(A[i]<A[j]) //if parent is smaller than child, then swap
        {
            //swap
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j; //i will come at the place of j(child)
            j=2*j; //move j to its left child
        }
        else
            break;
    }
    return val; //val is the deleted value
}

//Sorts the array using heap sort
void MXHheapSort(int A[], int n) //n last index of array
{
    int x,i,j,temp,val;
    val=A[1]; //deleted value is taken at val
    x=A[n]; //last element is taken to x
    A[1]=A[n]; //last element is copied to first
    A[n]=val; //deleted value is copied to last

    i=1; //i is index 1
    j=2*i; //j is at left child of i
    while(j < n-1) //n-1 is the end of the heap
    {
        if(A[j+1]>A[j]) //compare left and right child, and let j point on greater child
            j=j+1; //if right child greater, j point to right child
        if(A[i]<A[j]) //if parent is smaller than child, then swap
        {
            //swap
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j; //i will come at the place of j(child)
            j=2*j; //move j to its left child
        }
        else
            break;
    }
    A[n] = x; //last free space is n; deleting the element and copying at the last space
}

//Traverse the heap array sequentially and print the keys
void MXHtraverse(int A[])
{
    int i;
    for(i=1;i<=7;i++)
        printf("%d ",A[i]);
    printf("\n");
}


int main()
{
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

    return 0;
}

