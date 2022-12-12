#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>

typedef struct ListNode_t {
    struct ListNode_t *next;
    int value;
} ListNode;

typedef struct LinkedList_t {
    ListNode *firstMember;
//    ListNode *lastMember; // TODO use this
//    int length; // TODO use this
} LinkedList;

LinkedList newList();

void freeList(LinkedList *list);

int getListLength(LinkedList *list);

ListNode *getLastListMember(LinkedList *list);

bool listMemberExistsAtIndex(LinkedList *list, uint index);

ListNode *getListNodeAtIndex(LinkedList *list, uint index);

int getListValueAtIndex(LinkedList *list, uint index);

void setListValueAtIndex(LinkedList *list, uint index, int value);

void insertListValueAtIndex(LinkedList *list, uint index, int value);

void removeListValueAtIndex(LinkedList *list, uint index);

void appendListValue(LinkedList *list, int value);

// Append all values from list2 to the end of list1
void concatList(LinkedList *list1, LinkedList *list2);

void printList(LinkedList *list);

#endif
