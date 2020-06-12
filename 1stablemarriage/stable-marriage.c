#include <stdio.h>
#include <stdlib.h>
#include "../myLibs/LinkedList.h"

/*
    A simple program that solves the stable marriage problem using the Gale-Shapley algorithm.
*/

// Structs
struct Man {
    int lastWomman;
    int* prefList;
} typedef Man;

struct Woman {
    int *prefList;
} typedef Woman;

// Global Variables
Man** manList;
Woman** womanList;
int* pairs;
int numberOfPairs;

// Functions
void gale_shapley() {
    pairs = (int*) malloc (sizeof(int) * numberOfPairs);
    LinkedList* queue = emptyList();

    for (int i = 0; i < numberOfPairs; i++) {
        append(queue, i + 1);
        pairs[i] = -1;
    }

    while (queue->first != NULL) {
        int id = popFirst(queue);
        Man* selected = manList[id - 1];
        int womanId = selected->prefList[selected->lastWomman++];
        Woman* woman = womanList[womanId - 1];
        int partnerId = pairs[womanId -1];

        if(partnerId == -1) {
            pairs[womanId - 1] = id;
        } else if(woman->prefList[id - 1] < woman->prefList[partnerId - 1]) {
            pairs[womanId - 1] = id;
            append(queue, partnerId);
        } else {
            append(queue, id);
        }
    }
}

void printPairLists() {
    for (int i = 0; i < numberOfPairs; i++) {
        printf("Man id: %i, With pref list: \n", i + 1);
        for (int j = 0; j < numberOfPairs; j++)
            printf("%i ", manList[i]->prefList[j]);
        printf("\n");
    }
    for (int i = 0; i < numberOfPairs; i++) {
        printf("Woman id: %i, With pref list: \n", i + 1);
        for (int j = 0; j < numberOfPairs; j++)
            printf("%i ", womanList[i]->prefList[j]);
        printf("\n");
    }
}

void read() {
    scanf("%i", &numberOfPairs);
    int amoutOfEntries = (numberOfPairs + 1)*2*numberOfPairs;
    int* entryList = (int*) malloc(sizeof(int) * amoutOfEntries);
    int i = 0;
    int entry;
    int result = scanf("%i", &entry);
    while (result != EOF) {
        entryList[i++] = entry;
        result = scanf("%i", &entry);
    }
 
    manList = (Man**) malloc(sizeof(Man*) * numberOfPairs);
    womanList = (Woman**) malloc(sizeof(Woman*) * numberOfPairs);

    for (int i = 0; i < numberOfPairs; i++)
        womanList[i] = NULL;

    for (int start = 0; start < amoutOfEntries; start += numberOfPairs + 1) {
        int id = entryList[start];

        if(womanList[id - 1] == NULL)  {
            Woman* woman = (Woman*) malloc(sizeof(Woman));
            woman->prefList = (int*) malloc(sizeof(int)*numberOfPairs);

            for (int i = 0; i < numberOfPairs; i++)
                woman->prefList[entryList[start + i + 1] - 1] = i;

            womanList[id - 1] = woman; 
        } else {
            Man* man = (Man*) malloc(sizeof(Man));
            man->prefList = (int*) malloc(sizeof(int)*numberOfPairs);
            man->lastWomman = 0;

            for (int i = 0; i < numberOfPairs; i++) {
                man->prefList[i] = entryList[start + 1 + i];
            }
            manList[id - 1] = man;
        }
    }
    free(entryList);
}

int main() {
    
    read();
    gale_shapley();

    for (int i = 0; i < numberOfPairs; i++)
        printf("%i\n", pairs[i]);

    return 0;
}