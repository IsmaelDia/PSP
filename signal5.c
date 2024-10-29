#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

int cont = 0;

void manejador(int numsenal) {
    
    if (numsenal == SIGUSR1){
         printf("Proceso %d: Recibiendo señal de finalización.\n", getpid());
        exit(0);
    }
}

int main() {
    int fd[2], num;
    pid_t pid1, pid2;

    pipe(fd);

    pid1 = fork();

    if (pid1 == 0){
        close(fd[1]);
        signal(SIGUSR1, manejador); 

        while (1) {
            read(fd[0], &num, sizeof(int));
            if (num % 2 == 0) {
                printf("Soy el proceso P2 con PID: %d y este es el numero par recibido: %d\n", getpid(), num);
            }
        }
        close(fd[0]);
    }

    else{
        pid2 = fork();
        if (pid2 == 0){
            close(fd[1]);
            signal(SIGUSR1, manejador); 

        while (1) {
                read(fd[0], &num, sizeof(int));
                if (num % 2 == 1) {
                    printf("Soy el proceso P3 con PID: %d y este es el numero impar recibido: %d\n", getpid(), num);
                }
            }
            close(fd[0]);
        }

        close (fd[0]);
        do {
        printf("Escribe un número o 0 para salir: ");
        scanf("%d", &num);
        write(fd[1], &num, sizeof(num));
        if (num == 0) {
            kill(pid1, SIGUSR1); 
            kill(pid2, SIGUSR1); 
        }
        usleep(10000);
    } while (num != 0);
        close(fd[1]);
    wait(NULL);
    wait(NULL);
        
    }

    return 0;
}