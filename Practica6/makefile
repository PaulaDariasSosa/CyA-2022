# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 6: Simulación de autómatas finitos
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 08/11/2022
# Archivo makefile: archivo para la compilacion
# Referencias:
# Historial de revisiones
# 07/11/2022 - Creación (primera versión) del código
CC=g++
CXXFLAGS= -Wall -std=c++17 -g

OBJS= simbolo.o alfabeto.o cadena.o estado.o automata.o funciones.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p06_automata_simulator ${OBJS}

clean:
	rm -rf *.o p06_automata_simulator