#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid, pid_hijo, pid_nieto; 

    
    varpid = fork();


    if (varpid == 0) { 
        printf("Soy el proceso P2, mi PID es: %d y el de mi padre es: %d\n", getpid(), getppid());
        wait(NULL);
        
        
        pid_nieto = fork();
        
        
        if (pid_nieto == 0){
        printf("Soy el proceso P3, mi PID es: %d y el de mi padre es: %d\n", getpid(), getppid());
        exit(0);
        }
        
        
        else {
        wait(NULL);
        }
        
         
    } else {
          pid_hijo = varpid; 
          wait(NULL);
        printf("Soy el proceso P1, mi PID es: %d, el PID de mi hijo es: %d\n", getpid(), pid_hijo);
                
        }

     return 0;
    }


