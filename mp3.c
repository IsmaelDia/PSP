#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid, pid_hijo2; 

    
    varpid = fork();

	//SOY EL HIJO 1
    if (varpid == 0) {
    	sleep(10); 
        printf("P2 Despierto\n");
        exit(0); 
    } 
    
    //SOY EL PADRE
    else {
          pid_hijo2 = fork();
          //SOY EL HIJO 2
          if(pid_hijo2 == 0){
          	   printf("Soy el proceso P3, mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
          }
          else{
          wait(NULL);
          wait(NULL);    
        }
        }

     return 0;
    }


