#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2]; 
    pid_t pid;
    int numbers[] = {25, 18, 67, 42}; // Números a enviar
    int sum = 0;

    // Crear el pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    
    // Crear un nuevo proceso
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Proceso hijo
        close(fd[1]); // Cerrar el extremo de escritura del pipe
        int number;
        char end_char;

        // Leer números del pipe
        for (int i = 0; i < 4; i++) { // Cambia este número si cambias la cantidad de números
            read(fd[0], &number, sizeof(int));
            printf("Número recibido: %d\n", number);
            sum += number; 
        }
        
        // Leer el carácter de finalización
        read(fd[0], &end_char, sizeof(char));
        printf("Recibido carácter +\n");
        printf("La suma total es igual a: %d\n", sum);
        
        close(fd[0]); // Cerrar el extremo de lectura
    } else { // Proceso padre
        close(fd[0]); // Cerrar el extremo de lectura

        // Enviar números al pipe
        for (int i = 0; i < 4; i++) { // Cambia este número si cambias la cantidad de números
            write(fd[1], &numbers[i], sizeof(int)); // Envía el número al pipe
        }

        char end_char = '+'; // Caracter para finalizar
        write(fd[1], &end_char, sizeof(char)); // Envía el carácter +
        
        close(fd[1]); // Cerrar el extremo de escritura
        wait(NULL); // Espera a que el hijo termine
    }

    return 0;
}
