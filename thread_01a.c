#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* run(void* data) {
 printf("hola desde hilo");
}

int main(int argc, char** argv) {
 int rc;
 pthread_t tid;
 if ( (rc = pthread_create(&tid, NULL, run, NULL)) < 0) {
  perror("pthread_create()");
 }
 printf("hola desde main\n");
}
