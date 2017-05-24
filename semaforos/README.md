# Actividades a desarrollar con los codigos en este repositorio

## Notas preliminares

Para los siguientes programas  usted debe estar familiarizado con algunos datos que sirven para gestionar semáforos.

* Siempre incluya el archivo de cabecera `semaphore.h`.
* Antes de usar un semáforo debe crearlo. La función para creas los semáforos es `sem_open(char*, int oflag,...)`, donde `char*` es el nombre que usted desee ponerle al semáforo y `o_flag` indica como inicializar el archivo. Aquí un ejemplo

```
#define SEMNAME "/mysemaphore"
...
s = sem_open(SEMNAME, O_CREAT, S_IRUSR | S_IWUSR, 0);
```

En Internet usted podrá encontrar lo que significan las constantes `O_CREAT`, `S_IRUSR` y `S_IWUSR`. El `0` representa el valor en el que se desea inicializar el semáforo.

* `sem_wait(s)` esta función decrementa el contador del semáforo y en caso de alcanzar un valor menor que 0, bloquea al hilo o proceso que invoco esta función.

* `sem_post(s)` esta función incrementa el contador del semáforo y en caso de alcanzar un valor menor o igual a 0 entonces desbloquea a un hilo o proceso que se haya quedado bloqueado previamente por razón de este semáforo.

* Siempre se debe cerrar el semáforo y desligarlo del sistema de archivos.
```
sem_close(s);
sem_unlink(SEMNAME);
```

### Ejemplo

Observe el archivo `sharedsem.c`. Este es un ejemplo de como dos procesos comparten un semáforo y a través de él logran su coordinación. Observe que no importa lo rápido que se comporte el padre, este siempre esperará a su hijo ya que el invoca `sem_wait` y solo su hijo lo puede desbloquear al invocar `sem_post`.

Compile y ejecute el programa con el siguiente comando `gcc -o sharedsem sharedsem.c -pthread ; ./sharedsem `.

## Descripción de los códigos en este directorio
* `sembook-proble-3.1.c` suponga que existen dos hilos (A y B) y lo que se quiere es garantizar siempre la ejecución de una instruccion en A y luego una instruccion en B. Compile el programa de la siguiente manera

```
gcc -pthread sembook-proble-3.1.c -o sem-3.1
```

Ejecute el programa (`./sem-3.1`) y observe que si no se coordinan de forma correcta, el hilo B puede no imprimir ninguna cadena. Este programa debería imprimir algo similar a esto:

```
	On thread 'b'
	On thread 'a'
	[b] hola
```

	+ ¿Cómo usaría usted `sem_signal` y `sem_post` para garantizar que el proceso B siempre encontrara la cadena `hola` para imprimir?
	+ Modifique este programa de modo que en lugar de crear semáforos, se creen procesos como en el código `sharedsem.c`.

* `sembook-proble-3.3.c`. Suponga que tenemos dos hilos (A y B) que tienen líneas de código `a1`, `a2`, `b1` y `b2`. Los hilos se deben ejecutar de forma que a la hora de correr el programa `a1` ocurra antes de `b2` y `b1` antes de `a2`. Modifique el programa de modo que estas condiciones se cumplan.

* `3s-04.c` Identifique dentro del prorgrama aquellas regiones críticas y cambie las instrucciones que usan `pthread_mutex` por `sem_wait`, `sem_post`.

* `sembook-proble-3.5.c` Este programa simula el acceso de `m` personas a un salón de baile con capacidad para `n` personas y donde `m > n`. Modifique el código de modo que se garantice el acceso solo de `n` personas a la vez.
