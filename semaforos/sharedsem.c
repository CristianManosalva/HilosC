/**
Ejemplo de dos procesos compartiendo un semaforo. Tomado de https://stackoverflow.com/questions/2294584/how-can-i-get-multiple-calls-to-sem-open-working-in-c y modificado para efectos didacticos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

static void parent(void)
{
    sem_t * sem_id;
    sem_id=sem_open("mysem", O_CREAT, 0600, 0);
    printf("waiting for child\n");
    sem_wait(sem_id);
}

static void child(void)
{
    sem_t * sem_id;
    sem_id=sem_open("mysem", O_CREAT, 0600, 0);
    sleep(2);
    printf("Posting for parent\n");
    sem_post(sem_id);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    pid=fork();
    if(pid == 0) {
        child();    
    } else {
        int status;
        parent();
        wait(&status);
    }
    return 0;
}
