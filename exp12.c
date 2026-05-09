#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
pthread_t philosophers[N];

void *philosopher(void *num)
{
    int id = *(int *)num;

    printf("Philosopher %d is thinking\n", id);

    // Pick left fork
    sem_wait(&forks[id]);
    printf("Philosopher %d picked up left fork\n", id);

    // Pick right fork
    sem_wait(&forks[(id + 1) % N]);
    printf("Philosopher %d picked up right fork\n", id);

    // Eating
    printf("Philosopher %d is eating\n", id);
    sleep(1);

    
    sem_post(&forks[(id + 1) % N]);

    sem_post(&forks[id]);

    printf("Philosopher %d finished eating\n", id);

    return NULL;
}

int main()
{
    int i;
    int phil[N];

    
    for(i = 0; i < N; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

  
    for(i = 0; i < N; i++)
    {
        phil[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &phil[i]);
    }

    
    for(i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}