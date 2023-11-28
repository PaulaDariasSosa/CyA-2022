/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo funciones.h: declaracion de la funcion Usage y del texto de ayuda
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <string>

const std::string kHelpText = "El programa lee un fichero de entrada en el que se especifica una gramatica y la pasa a forma normal de Chomsky.  \
Para ejecutar el programa necesita introducir: ./p08_grammar2CNF input.gra output.gra";

void Usage(int argc, char *argv[]);