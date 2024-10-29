#include <time.h>
#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

FILE *logFile;

void manejador(int numsenal) {
     time_t hora;
    char *fecha;
    time(&hora);
    fecha = ctime(&hora);
    
    fprintf(logFile, "Señal SIGINT recibida : %s", fecha);
    fflush(logFile);
}
  
int main() 
{ 

    logFile = fopen("salidas.txt", "a");
    signal(SIGINT, manejador);
    signal(SIGKILL, SIG_IGN);
    while(1) {
        pause();
    }
     fclose(logFile);
    return 0; 
} 
