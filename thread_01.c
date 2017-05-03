#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// incluir archivo de cabecera de los Pthreads
// Para compilar gcc -o thread_01 thread_01.c -lpthread

// escribir aqui el prototipo de la funcion que espera recibir la funcion para
// la creacion de hilos. La funcion se debe llamar "run"
void* run(void* x) {
 sleep(1);
 printf("hola desde hilo\n");
 return NULL;
}

int main(int argc, char** argv) {
 int rc;
 // 1- defina una variable llamada "tid" que es del tipo de dato que usa la 
 //    libreria Pthread para identificar a los hilos
 // 2- Escriba las lineas de codigo que permitan la creacion de un hilo Y
 //    validen que el hilo se creo correctamente.
 //    Hint: si el valor que devuelve la funcion para creacion de hilos es < 0
 //          eso quiere decir que hubo un error
 if ( ) {
  perror("pthread_create()");
 }
 printf("hola desde main\n");

 return 0;
}
