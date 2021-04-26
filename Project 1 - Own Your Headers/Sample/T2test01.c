#include "MBHsll.h"

int main()
{
    puts("Name: Md. Bakhtiar Hasan");
    puts("Student ID: 144401");
    printf("\n\n");
    puts("Singly Linked List\n");
    sll *h = NULL;
    puts("Adding 1 to the beginning");
    h = SLLaddFirst(h, 1);
    puts("Traversing");
    SLLtraverse(h);
    puts("Adding 2 to the beginning");
    h = SLLaddFirst(h, 2);
    puts("Traversing");
    SLLtraverse(h);
    puts("Adding 6 to the end");
    h = SLLaddLast(h, 6);
    puts("Traversing");
    SLLtraverse(h);
    puts("Adding 7 after 6");
    h = SLLinsertAfter(h, 6, 7);
    puts("Traversing");
    SLLtraverse(h);
    puts("Adding 8 before 6");
    h = SLLinsertBefore(h, 6, 8);
    puts("Traversing");
    SLLtraverse(h);
    puts("Deleting 6");
    h = SLLdelete(h, 6);
    puts("Traversing");
    SLLtraverse(h);
    printf("\n\n");
    return 0;
}
