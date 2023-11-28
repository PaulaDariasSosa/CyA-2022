// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo funciones.h: programa que contiene la declaracion de Usage
// Contiene las funciones Usage, que le indica al usuaio como ejecutar el programa,
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cctype>
#include "cadena.h"
#include "lenguaje.h"

const std::string kHelpText = "El programa usa las clases simbolo, cadena, alfabeto y lenguaje \
para identificar los posibles lenguajes y las operaciones a realizar de un documento de texto e imprimir \
por pantalla la solucion de cada operacion. \
El usuario deberá introducir: ./p03_calculator y un documento de entrada, las declaraciones de cada lenguaje deberan tener: un identificador \
seguido = y las cadenas del lenguaje deberan estar separadas por comas y espacios. Ejemplo: LX = {X, X, X} \
Para escribir el lenguaje vacio es necesario no dejar un espacio entre las llaves.";

void Usage(int argc, char *argv[]);
