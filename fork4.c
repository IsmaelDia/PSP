#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t varpid,pid_padre, pid_hijo2, pid_nieto, pid_nieto2; 


	int acumulado = getpid();
    
    varpid = fork();

	//SOY EL HIJO 1
    if (varpid == 0) {
        if (getpid() %2== 0){
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado + 10);
        }
        else{
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado - 100);
        }
       pid_nieto = fork();
       
       if (pid_nieto == 0) {
               if (getpid() %2== 0){
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado + 10);
        }
        else{
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado - 100);
        }
          exit(0);
       }
       wait(NULL);
      exit(0);
    }

    else {
    printf("PID: %d\n", getpid());
          	  pid_hijo2 = fork();
    if (pid_hijo2 == 0) {
        if (getpid() %2== 0){
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado + 10);
        }
        else{
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado - 100);
        }
       pid_nieto2 = fork();
       
       if (pid_nieto2 == 0) {
               if (getpid() %2== 0){
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado + 10);
        }
        else{
        printf("Mi pid: %d, el resultado: %d\n",getpid(), acumulado - 100);
        }
          exit(0);
       }
       wait(NULL);
	exit(0);
        }
       wait(NULL);
       wait(NULL);
        }
     return 0;
   
    }

