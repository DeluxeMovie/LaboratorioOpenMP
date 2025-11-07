/************************************************
* Universidad: Pontificia Universidad Javeriana
* Nombre: Angel Daniel Garcia Santana
* Fecha: 4/11/2025
* Tema: Programación Paralela - Introducción OpenMP
* --------------------------------------------------
* ==================================================
* Resumen
* El programa usa OpenMP para paralelizar un ciclo que realiza sumas.
* Cada hilo calcula operaciones independientes con variables privadas.
* Al final muestra los valores de las variables compartidas después de la ejecución paralela.
**************************************************/

#include <omp.h> // Interfaz para OpenMP
#include <stdio.h> // Biblioteca para printf
#include <stdlib.h>

int main(){
	int i; // Variable de control del ciclo
	const int N = 1000; // Número total de iteraciones
	int a = 50; // Variable 'a' inicializada en 50
	int b = 0; // Variable 'b' inicializada en 0

// Directiva para paralelizar el ciclo for
#pragma omp parallel for private(i) shared(a) reduction(+:b)
	// En la variable b se acumula el valor 50 + i n veces
	for (i=0; i<N; i++){
		b = a + i;
	}
	// Imprime la variable a y b
	printf("a = %d b = %d (Se espera a =50 b= 2696 )\n", a,b);
	return 0;
}
