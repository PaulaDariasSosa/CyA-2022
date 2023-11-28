# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica #08: Gramáticas en Forma Normal de Chomsky
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 21/11/2022
# Archivo makefile: archivo para la compilacion
# Referencias:
# Historial de revisiones
# 21/11/2022 - Creación (primera versión) del código
CC=g++
CXXFLAGS= -Wall -std=c++17 -g

OBJS= simbolo.o alfabeto.o cadena.o gramatica.o producciones.o funciones.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p08_grammar2CNF ${OBJS}

clean:
	rm -rf *.o p08_grammar2CNF