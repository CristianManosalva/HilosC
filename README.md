Directorio con ejemplos son hilos en Sistemas Operativos
========================================================

En este repositorio encontraran algunos ejemplos respecto a la utilidad de los hilos en el contexto de los sistemas operativos.

* **fork.c** y **thread.c** Este par archivos evidencian las ventajas a la hora de crear hilos de ejecucion versus el crear procesos con la llamada al sistema `fork()`
	* Compile `fork.c`, `gcc fork.c -o fork`

	* Ejecute el recien creado `fork`, `time ./fork` 

	* Compile `thread.c`, `gcc thread.c -o thread`

	* Ejecute el recien creado `thread`, `time ./thread`


* **threadprime.c** Este codigo evidencia las ventajas de usar hilos
	* Reduccion en el tiempo de ejecucion
	* Uso del procesador

Actividades
-----------

* Documente lo observado con los programas `fork` y `thread`.
* Para el codigo **threadprime.c**, ejecute el binario de compilar este codigo y grafique los tiempos de respuesta al ejecutar su codigo con 1, 2, 4, 8, 16, 32, 64 y 128; hilos. 
**Hint:** Haga los ajustes en el codigo para que uste pueda correr el programa con 64 y 128 hilos.
* Escriba un programa en C que haga lo siguiente
	* Incluya el archivo de cabecera `pthread.h`
	* El programa principal cree varios hilos y cada uno de ellos ejecuta un `hola n`, donde `n` es el identificador del hilo. **Hint:** use la funcion `pthread_self()`, detalles de la funcion [aqui](http://man7.org/linux/man-pages/man3/pthread_self.3.html)

* Compile el programa `hello32.c` y ejecutelo varias veces (5 esta bien). 
Observa algun patron en la salida de la ejecucion del programa


