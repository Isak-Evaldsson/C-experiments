#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct node_t{
    int val;
    struct node_t* next;
} node_t;


typedef struct LinkedList
{   
    int size;
    node_t* first;
} LinkedList;

LinkedList* emptyList();
void printList(LinkedList* list);
void append(LinkedList* list, int val);
int popFirst(LinkedList* list);

#endif