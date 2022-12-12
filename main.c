#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList *foo = newList();
    appendListValue(foo, 1);
    appendListValue(foo, 3);
    appendListValue(foo, 5);
    appendListValue(foo, 7);

    LinkedList *bar = newList();
    appendListValue(bar, 2);
    appendListValue(bar, 4);
    appendListValue(bar, 6);
    appendListValue(bar, 8);

    printf("List foo contents: ");
    printList(foo);

    printf("\nList bar contents: ");
    printList(bar);

    freeList(foo);

    return 0;
}
