#include <stdio.h>

#define IN 1
#define OUT 0

/* Exercise 1-12*/
void main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if(c != '\n' && c != ' ' && c != '\t') {
            state = IN;
            putchar(c);
        } else if(state == IN) {
            state == OUT;
            putchar('\n');   
        }
    }    
}