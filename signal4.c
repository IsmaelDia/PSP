#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int cont = 0;

void manejador(int numsenal) {
    time_t hora;
    char *fecha;
    time(&hora);
    fecha = ctime(&hora);    

    printf("Señal de alarma recibida a las %s\n", fecha);
}

int main() {
    int veces, segundos, i = 0;

    printf("¿Cuántas veces sonará la alarma?: ");
    scanf("%d", &veces);

    printf("¿Cada cuántos segundos se repetirá la alarma?: ");
    scanf("%d", &segundos);

    printf("Alarma activada \n");

    signal(SIGALRM, manejador);
        //pause();  


    while(i < veces) {
        alarm(segundos);
        i = i + 1;
        pause();
    }
    printf("Alarma desactivada\n ");

    return 0;
}