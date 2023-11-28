# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica #07: Gramática regular a partir de un DFA
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 20/12/2022
# Archivo makefile: archivo para la compilacion
# Referencias:
# Historial de revisiones
# 20/12/2022 - Creación (primera versión) del código
CC=g++
CXXFLAGS= -Wall -std=c++17 -g

OBJS= dinero.o cambio.o utilidades.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p11_cambio_dinero ${OBJS}

clean:
	rm -rf *.o p11_cambio_dinero