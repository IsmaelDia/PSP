#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid, pid_nieto, pid_hijo2; 

    
    varpid = fork();

	//SOY EL HIJO 1
    if (varpid == 0) {
    	if (getpid() % 2 == 0){  
        printf("Mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        }
        else{
        printf("mi PID es: %d\n", getpid());
        wait(NULL);
        }
        
        
        pid_nieto = fork();
        
        //SOY EL NIETO
        if (pid_nieto == 0){
        if (getpid() % 2 == 0){  
        printf("Mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        }
        else{
        printf("mi PID es: %d\n", getpid());
        }
        } 
        //exit(0); 
        
    } 
    
    //SOY EL PADRE
    else {
          pid_hijo2 = fork();
          //SOY EL HIJO 2
          if(pid_hijo2 == 0){
          	  if (getpid() %2== 0){  
        printf("Mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        }
        else{
        printf("mi PID es: %d\n", getpid());
        }
          }
          else{
           if (getpid() % 2 == 0){  
        printf("Mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        }
        else{
        printf("mi PID es: %d\n", getpid());
        }
          wait(NULL);
          wait(NULL);    
        }
        }

     return 0;
    }

