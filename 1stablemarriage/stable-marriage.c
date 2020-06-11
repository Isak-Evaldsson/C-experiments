#include <stdio.h>
#include <stdlib.h>

struct Man {
    int lastWomman;
    int* prefList;
} typedef Man;

struct Woman {
    int *prefList;
} typedef Woman;


int read(Man** manList, Woman** womanList) {
    char str[10];
    long numberOfPairs;
    
    fgets(str, sizeof(str), stdin);
    numberOfPairs = strtol(str, NULL, 10);
    manList = (Man**) malloc(sizeof(Man*) * numberOfPairs);
    womanList = (Woman**) malloc(sizeof(Woman*) * numberOfPairs);
    int found[numberOfPairs];

    for (int i = 0; i < 2*numberOfPairs; i++)
    {
        char *line = (char*) malloc(6*numberOfPairs+2);
        fgets(line, sizeof(str), stdin);
        printf(line);
        int id = strtol(line, &line, 10);

        
        if(found[id - 1])  {
            printf("Woman");
            Woman* woman = (Woman*) malloc(sizeof(Woman));
            int* prefList = (int*) malloc(sizeof(int)*numberOfPairs);

            for (int i = 0; i < numberOfPairs; i++)
                prefList[strtol(line, &line, 10)] = 0;

            womanList[id - 1] = woman;
            found[id - 1] = 1;    
        } else {
            Man* man = (Man*) malloc(sizeof(Man));
            int* prefList = (int*) malloc(sizeof(int)*numberOfPairs);

            for (int i = 0; i < numberOfPairs; i++)
                prefList[i] = strtol(line, &line, 10);

            manList[id - 1] = man;
        }
    }

    return numberOfPairs;
}

int main() {
    Man** manList;
    Woman** womanList;
    int numberOfPairs = read(manList, womanList);
    
    return 0;
}