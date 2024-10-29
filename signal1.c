#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void manejador(int numsenal) {
    time_t hora;
    char *fecha;
    time(&hora);
    fecha = ctime(&hora);
    printf("Fin del proceso %d: %s", getpid(), fecha);
}

int main() {
    time_t hora;
    char *fecha;

    time(&hora);
    fecha = ctime(&hora);
    printf("Inicio del proceso %d: %s", getpid(), fecha);

    signal(SIGINT, manejador);
        pause();  


    return 0;
}
