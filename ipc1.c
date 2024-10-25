#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[30];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de escritura
                printf("Soy el proceso hijo con PID: %d\n", getpid());
                read(fd[0], buffer, 20);
                printf("\t Mensaje leido del pipe: %s \n", buffer);
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                write(fd[1], "Lunes 14 de octubre", 20);  
                wait(NULL);    
     }
     
        
}
