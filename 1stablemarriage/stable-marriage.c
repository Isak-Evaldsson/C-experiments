#include <stdio.h>
#include <stdlib.h>

/*
    A simple program that solves the stable marriage problem
*/

struct Man {
    int lastWomman;
    int* prefList;
} typedef Man;

struct Woman {
    int *prefList;
} typedef Woman;

Man** manList;
Woman** womanList;
int numberOfPairs;

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

            for (int i = 0; i < numberOfPairs; i++)
                man->prefList[i] = strtol(line, &line, 10);
        
            manList[id - 1] = man;
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
    //printPairLists();
    
    
    return 0;
}

