#include "ArrayList.h"
#define ARRAYLIST_INITIAL_CAPACITY 10

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

void destroyArrayList(ArrayList* list) {
    free(list->array);
    free(list);
}