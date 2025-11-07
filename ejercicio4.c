/************************************************
 * Universidad: Pontificia Universidad Javeriana
 * Nombre: Angel Daniel Garcia Santana
 * Fecha: 4/11/2025
 * Tema: Programación Paralela - Introducción OpenMP
 * --------------------------------------------------
 * ==================================================
 * Resumen
 * Calcula la suma de senos en rangos triangulares usando paralelismo.
 * Multiple hilos dividen las 30,000 iteraciones y combinan sus resultados automáticamente
 * con la operación de reducción.
 ****************************************************/

#include <stdio.h>      // Interfaz para entrada/salida
#include <stdlib.h>     // Interfaz estándar
#include <time.h>       // Interfaz para funciones de tiempo
#include <omp.h>        // Interfaz para programación paralela
#include <math.h>       // Interfaz para funcion seno
#include <sys/time.h>   // Interfaz para gettimeofday

// Macro para encontrar el mínimo entre dos valores
#define MIN(x,y) (((x) < (y))? (x) : (y))

// Variables globales para medir el tiempo de ejecución
struct timeval inicio, fin;

// Función que inicia el cronómetro
void InicioMuestra(){
    gettimeofday(&inicio, (void *)0);
}

// Función que detiene el cronómetro y muestra el tiempo transcurrido
void FinMuestra(){
    gettimeofday(&fin, (void *)0);
    fin.tv_usec -= inicio.tv_usec;
    fin.tv_sec  -= inicio.tv_sec;
    double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec);
    printf("Tiempo de ejecución: %9.0f microsegundos\n", tiempo);
}

// Función que calcula la suma de senos en un rango específico
double f(int i) {
    // Calcular el rango de valores para esta iteración
    int j, start = i * (i + 1) / 2;  // Inicio del rango
    int finish = start + i;           // Fin del rango
    double return_val = 0;            // Acumulador del resultado
    
    // Sumar los senos de todos los números en el rango [start, finish)
    for(j = start; j < finish; j++)
        return_val += sin(j);         // Acumular el seno de cada número
    
    return return_val;                // Devolver la suma calculada
}

int main() {
    double sum = 0;      // Variable para la suma total
    int i, n = 30000;    // 'n' es el número de iteraciones
    
    // Iniciar medición del tiempo
    InicioMuestra();
    
    // Región paralela donde múltiples hilos trabajan juntos
    #pragma omp parallel
    {
        // Solo un hilo (el maestro) obtiene y muestra el número total de hilos
        int threads = omp_get_num_threads();
        #pragma omp master
        printf("Número de Hilos: %d \n", threads);
        
        // Dividir el trabajo del ciclo for entre todos los hilos
        // 'reduction' combina las sumas parciales de cada hilo en una suma total
        #pragma omp for reduction(+ : sum)
        for (i = 0; i <= n; i++) {
            // Cada hilo calcula su parte y la suma se combina automáticamente
            sum += f(i);
        }
    }
    
    // Detener medición y mostrar resultados
    FinMuestra();
    
    // Mostrar el resultado final de la suma total
    printf("La sumatoria es: %.2f\n", sum);
    
    return 0;
}
