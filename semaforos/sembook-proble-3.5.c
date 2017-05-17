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
#define MAXTHREADS 20
#define ROOMSIZE 4

void enElSalon(int x) {
 int delay;
 delay = rand() % 5;
 printf("[%d] ESTA DE PARTY por %d segundos\n",x,delay);
 sleep(delay);
}
void *party(void *data) {
 int id = (int) data;
 printf("[%d] quiere entrar al salon\n",id);
 enElSalon(id);
 printf("[%d] se va del party\n",id);
 pthread_exit(0);
}

int main(int argc, char **argv) {
 pthread_t *threads;
 int i;

 srand(time(NULL));
 threads = (pthread_t*) malloc(sizeof(pthread_t)*MAXTHREADS);
 for (i = 0; i < MAXTHREADS; i++) { 
	pthread_create(&threads[i], NULL, party, (void*) i);
 }
 for (i = 0; i < MAXTHREADS; i++) { 
	pthread_join(threads[i], NULL);
 }

 pthread_exit(0);
}
