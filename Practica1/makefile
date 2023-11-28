# Universidad de La Laguna
# Escuela Superior de Ingenier´ıa y Tecnolog´ıa
# Grado en Ingenier´ıa Inform´atica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 1: Símbolos, alfabetos y cadenas
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 01/10/2022
# Archivo make: makefile.
# Referencias:
# Historial de revisiones
# 29/09/2022 - Creación (primera versión) del código
CC=g++
CXXFLAGS= -std=c++17 -g

OBJS= simbolo.o cadena.o alfabeto.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p01_strings ${OBJS}

clean:
	rm -rf *.o p01_strings