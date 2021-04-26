#include "MBHsll.h"

// Creates a new node that contains the value x and points to n.
node *SLLcreateNode(int val, node *n)
{
    node *temp; // declare a node
    temp = (node *)malloc(sizeof(struct SinglyLinkedList)); // allocate memory using malloc()
    temp->data = val; // assign data
    temp->next = n; // make next point to n
    return temp; //return the new node
}

// Adds a new node containing value  x to the front of the linked list
node *SLLaddFirst(node *head, int val)
{
    head = SLLcreateNode(val, head);
    return head;
}

// Adds a new node containing value x to the end of the linked list
node *SLLaddLast(node *head, int val)
{
    if(head == NULL)
        return SLLaddFirst(head, val);
    else
    {
        node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = SLLcreateNode(val, NULL);
        return head;
    }
}

// Finds the node containing k and insert a new node containing value v after it
node *SLLinsertAfter(node *head, int key, int val)
{
    node *temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;
    if(temp != NULL)
        temp->next = SLLcreateNode(val, temp->next);
    return head;
}

// Finds the node containing k and insert a new node containing value v before it
node *SLLinsertBefore(node *head, int key, int val)
{
    if(head->data == key)
        return SLLaddFirst(head, val);
    else
    {
        node *prev, *temp;
        temp = head;
        while(temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL)
            prev->next = SLLcreateNode(val, temp);
        return head;
    }
}

// Finds the node containing k and deletes it
node *SLLdelete(node *head, int key)
{
    if(head->data == key)
	{
        node *temp;
		temp = head->next;
		free(head);
		head = temp;
	}
	else
	{
		node *prev, *temp = head;
		while(temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}
		if(temp != NULL)
		{
			prev->next = temp->next;
			free(temp);
		}
	}
    return head;
}

// Traverse the linked list
void SLLtraverse(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}