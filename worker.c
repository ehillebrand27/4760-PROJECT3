

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMKEY 2031974

typedef struct {
    int seconds;
    int nanoseconds;
} Clock;

int main(int argc, char* argv[]){

    // take in command line options
    int interval_seconds = atoi(argv[1]);
    int interval_nanoseconds = atoi(argv[2]);

    // attach to shared memory
    int shmid = shmget(SHMKEY, sizeof(Clock), 0777);
    if (shmid == -1) {
        perror("worker error, shmget");
        exit(1);
    }

    //clock
    Clock *shm_clock = (Clock *) shmat(shmid, 0, 0);
    if (shm_clock == (void *) -1) {
        perror("Worker: shmat");
        exit(1);
    }


    return 0;
}
