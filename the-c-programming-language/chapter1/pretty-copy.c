#include <stdio.h>


/* Exercise 1-9 */
void main()
{
    int c, last;

    while ((c = getchar()) != EOF)
        if(c != ' ' || last != ' ') {
            putchar(c);
            last = c;
        }
}