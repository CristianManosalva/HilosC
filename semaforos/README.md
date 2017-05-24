# Actividades a desarrollar con los codigos en este repositorio
* `3s-04.c` Identifique dentro del prorgrama aquellas regiones críticas y cambie las instrucciones que usan `pthread_mutex` por `sem_wait`, `sem_post`.
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
