#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000000

int resultado = 0;
pthread_mutex_t mutex;

void* thread_func(void* arg) {
    int start = *((int*)arg);
    int end = start + (N / 2);
    int parcial = 0;

    for (int i = start; i < end; i++) {
        parcial += i;
    }

    pthread_mutex_lock(&mutex);
    resultado += parcial;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int start[2] = {1, N / 2 + 1};

    pthread_mutex_init(&mutex, NULL);

    // Cria as duas threads
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)&start[i]);
    }

    
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Resultado: %d\n", resultado);

    return 0;
}
