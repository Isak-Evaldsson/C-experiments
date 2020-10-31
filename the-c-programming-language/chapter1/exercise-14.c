#include <stdio.h>

#define NBR_OF_ALPHA 26
#define NBR_OF_DIGIT 10

void main() {
    int c;
    int char_frequency[NBR_OF_ALPHA + NBR_OF_DIGIT] = {0};

    while ((c = getchar()) != EOF) {
        if(c >= 'a' && c <= 'z') {
            char_frequency[c  - 'a']++; 
        } else if(c >= 'A' && c <= 'Z') {
            char_frequency[c  - 'A']++; 
        } else if(c >= '0' && c <= '9') {
            char_frequency[c - '0' + NBR_OF_ALPHA]++;
        }
    }

    printf("Char historgram\n---------------\n");
    for (int i = 0; i < (NBR_OF_ALPHA + NBR_OF_DIGIT); i++) {
        if(i < NBR_OF_ALPHA) {
            printf("%c: ", 'a' + i);
        } else {
            printf("%c: ", '0' + i - NBR_OF_ALPHA);
        }

        for (int j = 0; j < char_frequency[i]; j++)
        {
            putchar('#');
        }
        putchar('\n');
    }
    
}