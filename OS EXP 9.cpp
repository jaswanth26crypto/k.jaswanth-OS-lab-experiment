// Shared Memory IPC Program (Writer + Reader using fork)

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int shmid;
    key_t key = 5678;
    char *shm;

    // Create shared memory segment
    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid < 0)
    {
        printf("Shared memory creation failed\n");
        return 1;
    }

    // Attach shared memory
    shm = (char *)shmat(shmid, NULL, 0);

    if (shm == (char *)-1)
    {
        printf("Shared memory attach failed\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0)
    {
        // Parent Process (Writer)
        printf("Parent writing to shared memory...\n");

        strcpy(shm, "Hello from Parent Process");

        sleep(2);

        printf("Parent reads: %s\n", shm);
    }
    else if (pid == 0)
    {
        // Child Process (Reader)
        sleep(1);

        printf("Child reads: %s\n", shm);

        strcpy(shm, "Hello from Child Process");

        printf("Child updated shared memory\n");
    }
    else
    {
        printf("Fork failed\n");
        return 1;
    }

    // Detach shared memory
    shmdt(shm);

    // Remove shared memory (only parent should do this)
    if (pid > 0)
    {
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
