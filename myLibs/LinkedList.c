#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList* emptyList() {
    LinkedList* p = (LinkedList*) malloc(sizeof(LinkedList));
    p->first = NULL;
    return p;
}

node_t* createNode(int val) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->val = val;
    node->next = NULL;

    return node; 
}

void printList(LinkedList* list) {
    node_t* current = list->first;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void append(LinkedList* list, int val) {
    node_t* current = list->first;

    if(list->first == NULL) {
        list->first = createNode(val);
    } else {
        while (current->next != NULL)
            current = current->next;

        current->next = createNode(val);
    }
}

int popFirst(LinkedList* list) {
    node_t* fst = list->first;
    node_t* snd = NULL;
    int val = -1;

    if(fst == NULL) {
        return -1;
    }

    snd = fst->next;
    val = fst->val;
    free(fst);
    list->first = snd;

    return val;
}