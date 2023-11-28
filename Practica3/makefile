# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 3: Calculadora de lenguajes
# Autor: Paula María Darias Sosa
# Correo: alu0101398594@ull.es
# Fecha: 16/10/2022
# Archivo make: makefile.
# Referencias:
# Historial de revisiones
# 15/10/2022 - Creación (primera versión) del código
# 16/10/2022 - Correcion de constructor Lenguaje
# 17/10/2022 - Correcion de error generales
# 18/10/2022 - Correcion error entero potencia en documento

CC=g++
CXXFLAGS= -std=c++17 -g

OBJS= simbolo.o cadena.o alfabeto.o lenguaje.o calculadora.o main.o
all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p03_calculator ${OBJS}

clean:
	rm -rf *.o p03_calculator