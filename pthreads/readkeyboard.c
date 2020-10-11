#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t thread;

char getch() {
    char c;
    system("stty raw");
    c = getchar();
    system("stty sane");
    return c;
}

void *keyboard_input(void *arg) {
    char c;

    do {
        c = getch();
        printf("Got char: %c\n", c);
    } while (c != 'q');

    return NULL;
}

int main(int argc, char const *argv[])
{
    char c;
    printf("Stating keyboard input thread");
    pthread_create(&thread, NULL, keyboard_input, NULL);
    pthread_join(thread, NULL);
    printf("Exit Application");

    return 0;
}
