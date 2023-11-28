# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 4: Expresiones regulares
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 23/10/2022
# Archivo make: makefile.
# Referencias:
# Historial de revisiones
# 23/10/2022 - Creación (primera versión) del código

CC=g++
CXXFLAGS= -Wall -std=c++17 -g

OBJS= funciones.o Analizador.o Coincidencias.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p04_code_analyzer ${OBJS}

clean:
	rm -rf *.o p04_code_analyzer