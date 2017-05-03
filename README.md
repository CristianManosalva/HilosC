Directorio con ejemplos son hilos en Sistemas Operativos
========================================================

En este repositorio encontraran algunos ejemplos respecto a la utilidad de los hilos en el contexto de los sistemas operativos.

* **fork.c** y **thread.c** Este par archivos evidencian las ventajas a la hora de crear hilos de ejecucion versus el crear procesos con la llamada al sistema `fork()`
	* Compile `fork.c`, `gcc fork.c -o fork`

	* Ejecute el recien creado `fork`, `time ./fork` 

	* Compile `thread.c`, `gcc thread.c -o thread`

	* Ejecute el recien creado `thread`, `time ./thread`


