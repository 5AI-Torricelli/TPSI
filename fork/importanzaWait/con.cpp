#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main() {
    pid_t pid;
    int i;

    for (int i=0; i < 7; i++) {
        pid=fork();

        if(pid < 0) {
            perror("fork fallita");
            exit(0);
        } else if (pid == 0){
            printf("Figlio %d: PID %d: PPID %d\n", i+1, getpid(), getppid());
        }
        
        for(i = 0; i < 7; i++){

        wait(NULL);

        }

        printf("Padre(PID = %d) i processi sono stati terminati correttamente, \n, getpid()");
    }
    return 0;
}