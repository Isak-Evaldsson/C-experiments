#include <stdio.h>

/* Exercies 1-8 */
void main()
{
    int c, nl, tabs, blanks;

    nl = 0;
    tabs = 0;
    blanks = 0;

    while ((c = getchar()) != EOF)
        switch (c) {
            case '\n':
                nl++;
                break;
            case '\t':
                tabs++;
                break;
            case ' ':
                blanks++;
                break;
            default:
                break;
        }

    printf("Contains %d tabs, %d blanks and %d newlines.", tabs, blanks, nl);    
}