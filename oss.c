#include <stdio.h> 
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/wait.h> 
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define PERMS 0644
typedef struct msgbuffer {
long mtype;
char strData[100];
int intData;
} msgbuffer;


//shared memory key
#define SHMKEY 2031974
#define MAX_SIZE 256


//clock struct 
typedef struct {
    int seconds;
    int nanoseconds;
} Clock;


int main(int argc, char *argv[]){



    //parse options and receive the command parameters
    int n = 0;
    int s = 0;
    char f[100] = "";
    double t = 0.0;
    double i = 0.0;
    int opt;

    while ((opt = getopt(argc, argv, "n:s:t:i:f:")) != -1) {
    switch (opt) {
        case 'n':
            n = atoi(optarg);
            break;
        case 's':
            s = atoi(optarg);
            break;
        case 't':
            t = atof(optarg);
            break;
        case 'i':
            i = atof(optarg);
            break;
        case 'f':
            strncpy(f, optarg, sizeof(f) - 1); 
            f[sizeof(f) - 1] = '\0';
            break;
        }
    }

    // print parsed results to confirm. delete later
    printf("Parsed parameters:\n");
    printf("n = %d\n", n);
    printf("s = %d\n", s);
    printf("t = %.2f\n", t);
    printf("i = %.2f\n", i);
    printf("f = %s\n", f);




    //create shared memory
    int shmid = shmget(SHMKEY, sizeof(Clock), 0777 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }




    //clock
    Clock *shm_clock = (Clock *) shmat(shmid, 0, 0);
    if (shm_clock == (void *) -1) {
        perror("shmat");
        exit(1);
    }




    // get a key for our message queue
    key_t key;
    if ((key = ftok("msgq.txt", 1)) == -1) {
        perror("ftok");
        exit(1);
    }

    // create our message queue
    int msqid;
    if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
        perror("msgget in parent");
        exit(1);
    }




    // launch child
    pid_t pid;
    pid = fork();
    if(pid == 0){

    }


    
    return 0;
}