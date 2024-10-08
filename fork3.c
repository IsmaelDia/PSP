#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid,pid_padre, pid_hijo, pid_nieto, pid_nieto2, pid_bisnieto, pid_bisnieto2; 


	pid_padre = getpid();
    
    varpid = fork();

	//SOY EL HIJO 1
    if (varpid == 0) {
        printf("Soy P2 Mi PID es:%d\n", getpid());
        
        pid_hijo = getpid();
       
       pid_nieto = fork();
       
       if (pid_nieto == 0) {
               printf("Soy p3 Mi PID es: %d y el de mi abuelo es: %d\n", getpid(), pid_padre);
               
          pid_bisnieto = fork();
          
          if (pid_bisnieto == 0) {
               printf("soy p5 Mi PID es: %d y el de mi abuelo es: %d\n", getpid(), pid_hijo);
               exit(0);
          }
          
          wait(NULL);
                 exit(0);
       }
      pid_nieto2 = fork();
      if (pid_nieto2 == 0) {
               printf("soy p4 Mi PID es: %d y el de mi abuelo es: %d\n", getpid(), pid_padre);
               
               pid_bisnieto2 = fork();
          if (pid_bisnieto2 == 0) {
               printf("soy p6 Mi PID es: %d y el de mi abuelo es: %d\n", getpid(), pid_hijo);
               exit(0);
      }
      wait(NULL);
      exit(0);
      }
      wait(NULL);
      wait(NULL);
      
    }

    else {
          	   printf("Soy el proceso P1, mi PID es: %d\n", getpid());
          wait(NULL);
        }
     return 0;
    }

