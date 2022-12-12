#ifndef SINGLE_LINKED_LIST_SINGLELINKEDINTLIST_H
#define SINGLE_LINKED_LIST_SINGLELINKEDINTLIST_H

#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>

struct SingleLinkedIntListMember {
    struct SingleLinkedIntListMember *next;
    int value;
};

struct SingleLinkedIntList {
    struct SingleLinkedIntListMember *firstMember;
//    struct SingleLinkedIntListMember *lastMember; // TODO use this
//    int length; // TODO use this
};

int getListLength(struct SingleLinkedIntList *list) {
    if(!list->firstMember) return 0;
    else {
        int length = 1;
        struct SingleLinkedIntListMember *listMember = list->firstMember;
        while(listMember->next) {
            length++;
            listMember = listMember->next;
        }
        return length;
    }
}

struct SingleLinkedIntListMember *getLastListMember(struct SingleLinkedIntList *list) {
    struct SingleLinkedIntListMember *listMember = list->firstMember;
    while(listMember->next) {
        listMember = listMember->next;
    }
    return listMember;
}

bool listMemberExistsAtIndex(struct SingleLinkedIntList *list, uint index) {
    int currentIndex = 0;
    if(!list->firstMember) return false;
    struct SingleLinkedIntListMember *listMember = list->firstMember;
    while(currentIndex < index) {
        currentIndex++;
        if(!listMember->next) return false;
        listMember = listMember->next;
    }

    return true;
}

struct SingleLinkedIntListMember *getListMemberAtIndex(struct SingleLinkedIntList *list, uint index) {
    int currentIndex = 0;
    struct SingleLinkedIntListMember *listMember = list->firstMember;
    while(currentIndex < index && listMember->next) {
        currentIndex++;
        listMember = listMember->next;
    }

    return listMember;
}

int getListValueAtIndex(struct SingleLinkedIntList *list, uint index) {
    return getListMemberAtIndex(list, index)->value;
}

void setListValueAtIndex(struct SingleLinkedIntList *list, uint index, int value) {
    if(listMemberExistsAtIndex(list, index)) getListMemberAtIndex(list, index)->value = value;
}

void insertListValueAtIndex(struct SingleLinkedIntList *list, uint index, int value) {
    struct SingleLinkedIntListMember *currentMemberAtIndex = getListMemberAtIndex(list, index);

    struct SingleLinkedIntListMember *newMemberAtIndex = malloc(sizeof(struct SingleLinkedIntListMember));
    newMemberAtIndex->value = value;
    newMemberAtIndex->next = currentMemberAtIndex;

    if(index > 0) {
        struct SingleLinkedIntListMember *memberJustBeforeIndex = getListMemberAtIndex(list, index - 1);
        memberJustBeforeIndex->next = newMemberAtIndex;
    } else {
        list->firstMember = newMemberAtIndex;
    }
}

// TODO partially implemented
void removeListValueAtIndex(struct SingleLinkedIntList *list, uint index) {
    if(index > 0) {
        struct SingleLinkedIntListMember *memberJustBeforeIndex = getListMemberAtIndex(list, index - 1);
        if (memberJustBeforeIndex->next->next) {
            struct SingleLinkedIntListMember *memberToFree = memberJustBeforeIndex->next;
            memberJustBeforeIndex->next = memberJustBeforeIndex->next->next;
            free(memberToFree);
        }
    }
}

void appendListValue(struct SingleLinkedIntList *list, int value) {
    struct SingleLinkedIntListMember *newMember = malloc(sizeof(struct SingleLinkedIntListMember));
    newMember->value = value;
    newMember->next = NULL;

    if(list->firstMember) getLastListMember(list)->next = newMember;
    else list->firstMember = newMember;
}

#endif //SINGLE_LINKED_LIST_SINGLELINKEDINTLIST_H
