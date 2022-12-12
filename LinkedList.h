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

int getListLength(LinkedList *list);

ListNode *getLastListMember(LinkedList *list);

bool listMemberExistsAtIndex(LinkedList *list, uint index);

ListNode *getListMemberAtIndex(LinkedList *list, uint index);

int getListValueAtIndex(LinkedList *list, uint index);

void setListValueAtIndex(LinkedList *list, uint index, int value);

void insertListValueAtIndex(LinkedList *list, uint index, int value);

void removeListValueAtIndex(LinkedList *list, uint index);

void appendListValue(LinkedList *list, int value);

#endif
