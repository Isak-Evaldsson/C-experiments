#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *hello_pthreads(void *arg) {
    printf("Hello pthreads \n");

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t hello_thread;

    pthread_create(&hello_thread, NULL, hello_pthreads, NULL);
    pthread_join(hello_thread, NULL);

    return 0;
}
