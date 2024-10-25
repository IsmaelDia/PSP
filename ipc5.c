#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {	
    int fd1[2]; 
    int fd2[2];
    pid_t pid;
    int dni, factorial;
    char letra, letraDNI;

    pipe(fd1);
    pipe(fd2);
    
    pid = fork();


    if (pid == 0) { // Proceso hijo
    
     printf("Introduce tu DNI sin letra y sin espacios: ");
    scanf("%d", &dni);
    
        close(fd1[0]); 
        close (fd2[1]);

	write(fd1[1], &dni, sizeof(dni));
	
      
        close (fd1[1]);
        
        read(fd2[0], &letraDNI, sizeof(char));
        printf("La letra de tu DNI es: %c\n", letraDNI);
        
        close(fd2[0]); 
    } else { // Proceso padre
        close(fd1[1]); 
        close(fd2[0]);
	
	char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

        read(fd1[0], &dni, sizeof(int));

        close(fd1[0]);
        
        dni %= 23;
	letraDNI = ("%c",letra[dni]);
	
	write(fd2[1], &letraDNI, sizeof(letra)); 
        wait(NULL); 
        
    }

    return 0;
}
