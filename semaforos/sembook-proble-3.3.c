/*
Complete el siguiente programa de modo que a la hora de ejecutarse cumpla con
las siguientes condiciones
1- El enunciado "Statement a1" aparezca antes que el enunciado "Statement b2".
2- El enunciado "Statement b1" aparezca antes que el enunciado "Statement a2".

Para ello usted debe:
a- Crear las variables de tipo semaforo. AYUDA: con dos semaforos lo logra.
b- Inicializar los semaforos.
c- Incluir en las funciones 'statementA' y 'statementB' las instrucciones 
   'sem_wait' y 'sem_post' que se requiera.
d- Destruir los semaforos
*/
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>



void *statementA(void *data) {
 printf("Statement a1\n"); fflush(stdout);
 printf("Statement a2\n"); fflush(stdout);
 pthread_exit(0);
}

void *statementB(void *data) {
 printf("Statement b1\n"); fflush(stdout);
 printf("Statement b2\n"); fflush(stdout);
 pthread_exit(0);
}



int main(int argc, char **argv) {
 pthread_t threadA, threadB;
 int c;

 pthread_create(&threadA, NULL, statementA, (void*) c);
 pthread_create(&threadB, NULL, statementB, (void*) c);
 pthread_join(threadB, NULL);
 pthread_join(threadA, NULL);

 pthread_exit(0);
}
