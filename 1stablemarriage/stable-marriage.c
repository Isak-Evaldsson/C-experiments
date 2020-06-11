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
void read() {
    char str[10];
    fgets(str, sizeof(str), stdin);
    numberOfPairs = strtol(str, NULL, 10);
    manList = (Man**) malloc(sizeof(Man*) * numberOfPairs);
    womanList = (Woman**) malloc(sizeof(Woman*) * numberOfPairs);
    
    for (int i = 0; i < numberOfPairs; i++)
        womanList[i] = NULL;

    for (int i = 0; i < 2*numberOfPairs; i++)
    {
        char *line = (char*) malloc(6*numberOfPairs+2);
        fgets(line, 6*numberOfPairs+2, stdin);
        int id = strtol(line, &line, 10);
        
        if(womanList[id - 1] == NULL)  {
            Woman* woman = (Woman*) malloc(sizeof(Woman));
            woman->prefList = (int*) malloc(sizeof(int)*numberOfPairs);

            for (int i = 0; i < numberOfPairs; i++)
                woman->prefList[strtol(line, &line, 10) - 1] = i;

            womanList[id - 1] = woman; 
        } else {
            Man* man = (Man*) malloc(sizeof(Man));
            man->prefList = (int*) malloc(sizeof(int)*numberOfPairs);
            man->lastWomman = 0;

            for (int i = 0; i < numberOfPairs; i++)
                man->prefList[i] = strtol(line, &line, 10);
        
            manList[id - 1] = man;
        }
    }
}

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

int main() {
    read();
    gale_shapley();

    for (int i = 0; i < numberOfPairs; i++) {
        printf("%i\n", pairs[i]);
    }
    return 0;
}

