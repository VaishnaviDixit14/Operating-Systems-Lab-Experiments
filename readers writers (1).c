/*Write a program in C to implement a solution for Reader-Writer's problem.*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
sem_t mutex, resource, readCount;

int data = 0;
int readerCount = 0;

void *reader(void *arg) {
    int readerID = *(int *)arg;
    printf("Reader %d is trying to read.\n", readerID);

    // Acquire the mutex to protect the readerCount
    sem_wait(&mutex);

    // Increment the readerCount to indicate that a reader is active
    readerCount++;

    // If it's the first reader, acquire the resource semaphore to block writers
    if (readerCount == 1) {
        sem_wait(&resource);
    }

    // Release the mutex
    sem_post(&mutex);

    // Read the data
    printf("Reader %d is reading the data: %d\n", readerID, data);

    // Acquire the mutex to protect the readerCount
    sem_wait(&mutex);

    // Decrement the readerCount to indicate that a reader is finished
    readerCount--;

    // If it's the last reader, release the resource semaphore to allow writers
    if (readerCount == 0) {
        sem_post(&resource);
    }

    // Release the mutex
    sem_post(&mutex);

    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writerID = *(int *)arg;
    printf("Writer %d is trying to write.\n", writerID);

    // Acquire the resource semaphore to block both readers and writers
    sem_wait(&resource);

    // Write to the data
    data++;
    printf("Writer %d is writing the data: %d\n", writerID, data);

    // Release the resource semaphore to allow other readers or writers
    sem_post(&resource);

    pthread_exit(NULL);
}

int main() {
    int i, readerIDs[NUM_READERS], writerIDs[NUM_WRITERS];

    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&resource, 0, 1);
    sem_init(&readCount, 0, 1);

    // Create reader threads
    for (i = 0; i < NUM_READERS; i++) {
        readerIDs[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIDs[i]);
    }

    // Create writer threads
    for (i = 0; i < NUM_WRITERS; i++) {
        writerIDs[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIDs[i]);
    }

    // Wait for reader threads to finish
    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    // Wait for writer threads to finish
    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy the semaphores
    sem_destroy(&mutex);
    sem_destroy(&resource);
    sem_destroy(&readCount);

    return 0;
}




























