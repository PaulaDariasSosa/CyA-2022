/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo funciones.h: declaracion de la funcion Usage y del texto de ayuda
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código



#include <iostream>
#include <string>

const std::string kHelpText = "EL programa pasa de un DFA a una Gramatica. Para usarse correctamente se le debe pasar el ejecutable del propio programa, \
un fichero de entrada donde se defina el propio DFA, y un fichero de salida donde se escribira la definicion de la gramatica";

void Usage(int argc, char *argv[]);