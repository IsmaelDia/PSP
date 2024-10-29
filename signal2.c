#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int cont = 0;

void manejador(int numsenal) {
     cont += 5;
    

    printf("Han transcurrido %d segundos \n", cont);
}

int main() {

    signal(SIGALRM, manejador);
        //pause();  

    while(1) {
        alarm(5);
        pause();
    }

    return 0;
}
