#include <stdio.h>
#include "SingleLinkedIntList.h"

int main() {
    struct SingleLinkedIntList foo;
    foo.firstMember = NULL;

    appendListValue(&foo, 1);
    appendListValue(&foo, 3);
    appendListValue(&foo, 5);

    getListMemberAtIndex(&foo, 0);
    getListMemberAtIndex(&foo, 2);

    printf("Hello, World!\n");
    return 0;
}
