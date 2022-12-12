#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList foo;
    foo.firstMember = NULL;

    appendListValue(&foo, 1);
    appendListValue(&foo, 3);
    appendListValue(&foo, 5);

    printf("List contents: ");
    printList(&foo);

    return 0;
}
