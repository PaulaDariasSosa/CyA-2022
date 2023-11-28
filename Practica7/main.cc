/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo main.cc: funcion principal
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código
/// Se compila con: tar cfvz ~/p07_Paula_Darias.tgz ../Practica7/
#include <fstream>
#include <iostream>
#include "funciones.h"
#include "automata.h"
#include "gramatica.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kFileName1 = argv[1];
  std::string kFileName2 = argv[2];
  Automata prueba (kFileName1);
  Gramatica convertida = prueba.Pasar_A_Gramatica();
  convertida.Imprimir(kFileName2);
  return 0;
}