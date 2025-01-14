#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getln(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int getln(char line[], int maxline)
{
    int i, j, c;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < maxline - 2) {
            line[j] = c;
            ++j;
        }
    }

    if (c == '\n') {
        line[j] = c;
        ++j;
        ++i;
    }
    line[j] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
