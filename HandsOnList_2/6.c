#include <stdio.h>
#include <pthread.h>// For thread creation and management

void* thread_function(void* arg) {
    printf("Thread %d is running.\n", *(int*)arg);
    /* *(int*)arg: This is how we retrieve the argument passed to the thread. arg is a void*, so we cast it to int* to treat it as an integer pointer. Then, *(int*)arg dereferences the pointer to get the actual integer value (which represents the thread number).*/
    return NULL;
}

int main() {
    pthread_t threads[3];
    /*This declares an array of 3 pthread_t variables, which will store the identifiers for the 3 threads.*/
    int i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &i);//pthread_create() creates a new thread.
       //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
       /*&threads[i]: The first argument is the address of a pthread_t variable that stores the thread ID.
        NULL: The second argument is for thread attributes (we pass NULL for default attributes).
        thread_function: The third argument is the function the thread will execute.
        &i: The fourth argument is passed to the thread function. Here, we pass a pointer to the loop variable i, which identifies the thread number.*/
        pthread_join(threads[i], NULL);
        /*This function blocks the main thread and waits for the thread threads[i] to finish execution before continuing to the next iteration.*/
    }

    return 0;
}
