#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

#define ARRAYLIST_INITIAL_CAPACITY 4

struct ArrayList {
    unsigned int size;
    unsigned int capacity;
    int *array;
};

ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
    list->size = 0;
    list->capacity = ARRAYLIST_INITIAL_CAPACITY;
    list->array = (int*) malloc(sizeof(int) * ARRAYLIST_INITIAL_CAPACITY);

    return list;
}

void extend(ArrayList* list)  {
    unsigned int extendedCapacity = list->capacity*2;
    list->array = realloc(list->array, extendedCapacity);
    assert(list->array);
    list->capacity = extendedCapacity;
}

void set(ArrayList* list, unsigned int index, int value) {
    assert(index < list->size);
    list->array[index] = value;
}

int get(ArrayList* list, unsigned int index) {
    assert(index < list->size);
    return list->array[index];
}

void appendArrayList(ArrayList* list, int value){
    if(list->size + 1 > list->capacity) {
        extend(list);
    }
    list->array[list->size++] = value;
}

void destroyArrayList(ArrayList* list) {
    free(list->array);
    free(list);
}