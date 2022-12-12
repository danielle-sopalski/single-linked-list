#include "LinkedList.h"
#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <printf.h>

int getListLength(LinkedList *list) {
    if(!list->firstMember) return 0;
    else {
        int length = 1;
        ListNode *listMember = list->firstMember;
        while(listMember->next) {
            length++;
            listMember = listMember->next;
        }
        return length;
    }
}

ListNode *getLastListMember(LinkedList *list) {
    ListNode *listMember = list->firstMember;
    while(listMember->next) {
        listMember = listMember->next;
    }
    return listMember;
}

bool listMemberExistsAtIndex(LinkedList *list, uint index) {
    int currentIndex = 0;
    if(!list->firstMember) return false;
    ListNode *listMember = list->firstMember;
    while(currentIndex < index) {
        currentIndex++;
        if(!listMember->next) return false;
        listMember = listMember->next;
    }

    return true;
}

ListNode *getListNodeAtIndex(LinkedList *list, uint index) {
    int currentIndex = 0;
    ListNode *listMember = list->firstMember;
    while(currentIndex < index && listMember->next) {
        currentIndex++;
        listMember = listMember->next;
    }

    return listMember;
}

int getListValueAtIndex(LinkedList *list, uint index) {
    return getListNodeAtIndex(list, index)->value;
}

void setListValueAtIndex(LinkedList *list, uint index, int value) {
    if(listMemberExistsAtIndex(list, index)) getListNodeAtIndex(list, index)->value = value;
}

void insertListValueAtIndex(LinkedList *list, uint index, int value) {
    ListNode *currentMemberAtIndex = getListNodeAtIndex(list, index);

    ListNode *newMemberAtIndex = malloc(sizeof(ListNode));
    newMemberAtIndex->value = value;
    newMemberAtIndex->next = currentMemberAtIndex;

    if(index > 0) {
        ListNode *memberJustBeforeIndex = getListNodeAtIndex(list, index - 1);
        memberJustBeforeIndex->next = newMemberAtIndex;
    } else {
        list->firstMember = newMemberAtIndex;
    }
}

void removeListValueAtIndex(LinkedList *list, uint index) {
    if(index > 0) {
        ListNode *nodeJustBeforeIndex = getListNodeAtIndex(list, index - 1);
        ListNode *nodeToFree = nodeJustBeforeIndex->next;

        nodeJustBeforeIndex->next = nodeJustBeforeIndex->next->next ? nodeJustBeforeIndex->next->next : NULL;

        free(nodeToFree);
    } else {
        ListNode *newFirstNode = list->firstMember->next ? list->firstMember->next : NULL;
        free(list->firstMember);
        list->firstMember = newFirstNode;
    }
}

void appendListValue(LinkedList *list, int value) {
    ListNode *newMember = malloc(sizeof(ListNode));
    newMember->value = value;
    newMember->next = NULL;

    if(list->firstMember) getLastListMember(list)->next = newMember;
    else list->firstMember = newMember;
}

void printList(LinkedList *list) {
    printf("[");
    if(list->firstMember) {
        ListNode *listNode = list->firstMember;
        printf("%i", listNode->value);
        while(listNode->next) {
            printf(", ");
            listNode = listNode->next;
            printf("%i", listNode->value);
        }
    }
    printf("]");
}
