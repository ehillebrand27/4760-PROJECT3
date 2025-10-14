
#include <stdio.h>
#include <getopt.h>


struct PCB {
    int occupied; // either true or false
    pid_t pid; // process id of this child
    int startSeconds; // time when it was forked/created
    int startNano; // time when it was forked /created
    int messagesSent // total times oss sent a message to it
};
struct PCB processTable[20];

int main(int argc, char*argv[]){

    return 0;
}