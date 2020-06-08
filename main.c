#include <stdio.h>
#include "myLibs/LinkedList.h"

int main() {
    LinkedList* list = emptyList();
    append(list, 2);
    append(list, 4);
    popFirst(list);
    printf("%i",list->size);
    return 0;
}