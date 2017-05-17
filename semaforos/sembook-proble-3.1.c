/*
Este programa ilustra como dos hilos cooperativos sino son coordinados de forma 
apropiada traeran valores errados.
*/
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

#define A 'a'
#define B 'b'
#define MAXSTRING 20
#define FILENAME "hola.txt"

char *cadena;

void *fA(void *data) {
 char c = (char) data;
 FILE *f = fopen(FILENAME,"r");
 printf("On thread '%c'\n", c);
 cadena = (char*)malloc(sizeof(char)*MAXSTRING);
 fscanf(f,"%s",cadena);
 fclose(f);
 pthread_exit(0);
}

void *fB(void *data) {
 char c = (char) data;
 printf("On thread '%c'\n", c);
 printf("[%c] %s\n",c,cadena);
 pthread_exit(0);
}


int main(int argc, char **argv) {
 pthread_t threadA, threadB;
 char c;
 int i;

 c = A; pthread_create(&threadA, NULL, fA, (void*) c);
 c = B; pthread_create(&threadB, NULL, fB, (void*) c);
 pthread_join(threadB, NULL);
 pthread_join(threadA, NULL);
 free(cadena);

 pthread_exit(0);
}
