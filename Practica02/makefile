# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 2: Operaciones con lenguajes
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 12/10/2022
# Archivo make: makefile.
# Referencias:
# Historial de revisiones
# 09/10/2022 - Creación (primera versión) del código

CC=g++
CXXFLAGS= -std=c++17 -g

OBJS= simbolo.o cadena.o alfabeto.o lenguaje.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p02_languages ${OBJS}

clean:
	rm -rf *.o p02_languages