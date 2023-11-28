// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo funciones.h: declaracion de la funcion Usage y del texto de ayuda
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <string>

const std::string kHelpText = "El programa usa las clases simbolo, cadena, alfabeto y lenguaje \
para identificar los posibles lenguajes y las operaciones a realizar de un documento de texto e imprimir \
por pantalla la solucion de cada operacion. \
El usuario deberá introducir: ./p03_calculator y un documento de entrada, las declaraciones de cada lenguaje deberan tener: un identificador \
seguido = y las cadenas del lenguaje deberan estar separadas por comas y espacios. Ejemplo: LX = {X, X, X} \
Para escribir el lenguaje vacio es necesario no dejar un espacio entre las llaves.";

void Usage(int argc, char *argv[]);