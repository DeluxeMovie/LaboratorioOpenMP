# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -fopenmp
LDFLAGS = -fopenmp -lm

# Lista de ejecutables
EJECUTABLES = ejercicio1 ejercicio2 ejercicio3 ejercicio4

# Regla por defecto
all: $(EJECUTABLES)

# Reglas específicas para cada ejercicio
ejercicio1: ejercicio1.o
	$(CC) -o $@ $^ $(LDFLAGS)

ejercicio2: ejercicio2.o
	$(CC) -o $@ $^ $(LDFLAGS)

ejercicio3: ejercicio3.o
	$(CC) -o $@ $^ $(LDFLAGS)

ejercicio4: ejercicio4.o
	$(CC) -o $@ $^ $(LDFLAGS)

# Regla para archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(EJECUTABLES) *.o

# Ayuda
help:
	@echo "Opciones disponibles:"
	@echo "  all      - Compila todos los ejercicios (por defecto)"
	@echo "  clean    - Elimina los ejecutables y archivos objeto"
	@echo "  install  - Copia los ejecutables al directorio bin/"
	@echo "  help     - Muestra esta ayuda"

# Variables especiales
.DEFAULT_GOAL = all
