#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid, pid_hijo; 

    
    varpid = fork();


    if (varpid == 0) { 
        printf("Ismael\n");
        exit(0); 
    } else {
          pid_hijo = varpid; 
          wait(NULL);
        printf("Soy el padre, mi PID es: %d, el PID de mi hijo es: %d\n", getpid(), pid_hijo);
                
        }

     return 0;
    }


