/************************************************
* Universidad: Pontificia Universidad Javeriana
* Nombre: Angel Daniel Garcia Santana
* Fecha: 4/11/2025
* Tema: Programación Paralela - Introducción OpenMP
* --------------------------------------------------
* ==================================================
* Resumen
* El programa recibe como parámetro un número de hilos,
* muestra las capacidades del sistema y luego cada hilo creado imprime su propio saludo
* identificándose con su número único.
**************************************************/

#include <omp.h> // Interfaz para programación paralela con OpenMP
#include <stdio.h> // Interfaz para printf
#include <stdlib.h>

int main(int argc, char *argv[]){
	// Verificar que el número de argumentos sea 2, si es diferente de 2 muestra la manera correcta de compilar el programa
	if(argc!=2){
	printf("Error \n\t$./ejecutable numHilos\n\n");
	exit(0);
}
	// Convierte el argumento de texto a un número entero
	int numHilos = (int) atoi(argv[1]);	
	// Imprime el número ingresado por teclado inicialmente al compilar el programa
	printf("====== %d ===== \n", numHilos);
	// Obtiene el número máximo de hilos que el sistema puede ejecutar
	int maxHilos = omp_get_max_threads();
	// Imprime el número máximo de hilos que el sistema puede ejecutar
	printf("OpenMP ejecutando con %d hilos\n", maxHilos);
// Directiva para empezar a utilizar multiples hilos 
#pragma omp parallel
{
	// Cada hilo imprime su propio mensaje con su número identificador
	printf("Hello World desde el thread %d\n", omp_get_thread_num());
}
	return 0;
}
