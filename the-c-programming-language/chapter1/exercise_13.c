#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define SIZE 100

void main() {
    char c;
    int words[SIZE] = {0};
    int length = 0;
    int longestWord = 0;
    int new_word = FALSE;

    // Word counter
    while (TRUE) {
        c = getchar();
        if (c == ' ' || c == '\n' || c == '\t' || c == EOF) {
            if (!new_word) {
                new_word = TRUE;

                if (length > longestWord && length <= SIZE) {
                    longestWord = length;
                }

                if (length > SIZE) {
                    words[SIZE - 1]++;
                } else {
                    words[length - 1]++;
                }
                length = 0;
            }
            if (c == EOF)
                break;
        }
        else {
            new_word = FALSE;
            length++;
        }
    }

    //Histogram plotter
    printf("Word lenght frequencey:\n");
    for (int i = 0; i < longestWord; i++)
    {
        printf("%2d: ", i + 1);
        for (int j = 0; j < words[i]; j++)
        {
            putchar('#');
        }
        putchar('\n');
    }
}