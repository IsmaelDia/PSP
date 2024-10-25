#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int fd1[2]; 
    int fd2[2];
    pid_t pid;
    int num1, factorial;

    pipe(fd1);
    pipe(fd2);
    
    pid = fork();


    if (pid == 0) { // Proceso hijo
        close(fd1[1]); 
        close (fd2[0]);

	read(fd1[0], &num1, sizeof(int));
	
	factorial = 1;
      
          for (int i = 1; i <= num1; i++) {
            factorial *= i; 
        }
        
        close (fd1[0]);
        
        write(fd2[1], &factorial, sizeof(factorial));
        
        close(fd2[1]); 
    } else { // Proceso padre
        close(fd1[0]); 
        close(fd2[1]);
	srand(time(NULL));
        num1 = rand() % 10 + 1;

        write(fd1[1], &num1, sizeof(num1));

        close(fd1[1]); 
        wait(NULL); 
        
        read(fd2[0], &factorial, sizeof(int));
        
        printf("El factorial de %d es igual a: %d\n",num1, factorial);
        close(fd2[0]);
    }

    return 0;
}
