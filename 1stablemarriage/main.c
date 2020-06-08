#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct Man {
    LinkedList prefQueue;
} typedef Man;

struct Woman {
    int *prefList;
} typedef Woman;


void read() {
    char str[10];
    long numberOfPairs;
    
    fgets(str, sizeof(str), stdin);
    numberOfPairs = strtol(str, NULL, 10);


    for (int i = 0; i < 2*numberOfPairs; i++)
    {
        char *line = (char*) malloc(6*numberOfPairs+2);
        long id;
        long prefs[numberOfPairs];

        fgets(line, sizeof(str), stdin);
        id = strtol(line, &line, 10);

        for (int i = 0; i <= numberOfPairs; i++) {
            prefs[i] = strtol(line, &line, 10);
        };

    }
}

int main() {
    read();
    return 0;
}