#include "myLibs/LinkedList.h"

int main() {
    LinkedList* list = emptyList();
    append(list, 2);
    append(list, 4);
    printList(list);
    return 0;
}