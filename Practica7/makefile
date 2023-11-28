# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica #07: Gramática regular a partir de un DFA
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 14/11/2022
# Archivo makefile: archivo para la compilacion
# Referencias:
# Historial de revisiones
# 14/11/2022 - Creación (primera versión) del código
CC=g++
CXXFLAGS= -Wall -std=c++17 -g

OBJS= simbolo.o alfabeto.o cadena.o estado.o automata.o gramatica.o funciones.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p07_dfa2grammar ${OBJS}

clean:
	rm -rf *.o p07_dfa2grammar