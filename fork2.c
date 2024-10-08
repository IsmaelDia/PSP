#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid, pid_nieto, pid_bisnieto; 

    
    varpid = fork();

	//SOY EL HIJO 1
    if (varpid == 0) {
        printf("Soy el proceso P2, mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        int suma1 = getpid() + getppid();
        printf("La suma de ambos es: %d\n", suma1);
        
        pid_nieto = fork();
        
       
        if (pid_nieto == 0) {
        printf("Soy el proceso P3, mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        int suma2 = getpid() + getppid();
        printf("La suma de ambos es: %d\n", suma2);
        
        pid_bisnieto = fork();
        
        if (pid_bisnieto == 0) {
        printf("Soy el proceso P4, mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        int suma3 = getpid() + getppid();
        printf("La suma de ambos es: %d\n", suma3);
    }
   else {
                wait(NULL); 
            }
        } 
        else {
            wait(NULL); 
        }
    }

    //SOY EL PADRE
    else {
          printf("Soy el proceso P1, mi PID es: %d\n", getpid());
        wait (NULL);
        }
        

     return 0;
    }


