#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main (){
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
        
        printf("Padre (PID = %d) : non esegue il wait(), i figli saranno temporaneamente zombie \n", getpid());

        return 0;
    }
}