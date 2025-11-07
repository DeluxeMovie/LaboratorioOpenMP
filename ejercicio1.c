/************************************************
* Universidad: Pontificia Universidad Javeriana
* Nombre: Angel Daniel Garcia Santana
* Fecha: 4/11/2025
* Tema: Programación Paralela - Introducción OpenMP
* --------------------------------------------------
* ==================================================
* Resumen
* Programa crea hilos de ejecución para cada core
* Imprime cadena de caracteres por cada llamada.
**************************************************/

#include <omp.h> // Interfaz para usar OpenMP
#include <stdio.h> // Interfaz para printf
#include <stdlib.h> 

int main(int argc, char *argv[]){
	//Mostrar cuantos hilos máximo pude usar OpenMP
	printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());

	// Inicio de la directiva paralela de OpenMP, es decir desde este momento se ejecutan multiples hilos simultaneamente
	#pragma omp parallel
{
	// Cada hilo ejecuta esta linea independientemente
	// omp_get_thread_num() devuelve el número único de cada hilo
	printf("Hello World desde el thread %d\n", omp_get_thread_num());
}
	// Fin del programa
	return 0;
}
