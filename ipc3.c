#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int fd[2]; 
    pid_t pid;
    int numbers[2]; // Para almacenar los dos números aleatorios

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
        close(fd[0]); // Cerrar el extremo de lectura del pipe

        // Semilla para la generación de números aleatorios
        srand(time(NULL));

        // Generar dos números aleatorios entre 1 y 50
        numbers[0] = rand() % 50 + 1;
        numbers[1] = rand() % 50 + 1;

        // Escribir los números en el pipe
        write(fd[1], numbers, sizeof(numbers));
        
        close(fd[1]); // Cerrar el extremo de escritura
    } else { // Proceso padre
        close(fd[1]); // Cerrar el extremo de escritura

        // Leer los números del pipe
        read(fd[0], numbers, sizeof(numbers));

        // Calcular y mostrar los resultados
        int sum = numbers[0] + numbers[1];
        int difference = numbers[0] - numbers[1];
        int product = numbers[0] * numbers[1];
        int division = numbers[0] / numbers[1]; 

        printf("%d + %d = %d\n", numbers[0], numbers[1], sum);
        printf("%d - %d = %d\n", numbers[0], numbers[1], difference);
        printf("%d * %d = %d\n", numbers[0], numbers[1], product);
        printf("%d / %d = %d\n", numbers[0], numbers[1], division);
        
        close(fd[0]); // Cerrar el extremo de lectura
        wait(NULL); // Esperar a que el hijo termine
    }

    return 0;
}
