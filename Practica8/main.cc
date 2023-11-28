/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo main.cc: funcion principal
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código
/// Se compila con: tar cfvz ~/p08_Paula_Darias.tgz ../Practica8/
#include <fstream>
#include <iostream>
#include "funciones.h"
#include "gramatica.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kFileName1 = argv[1];
  std::string kFileName2 = argv[2];
  Gramatica aux (kFileName1);
  //aux.Imprimir(kFileName2);
  aux.Pasar_FN();
  aux.Imprimir(kFileName2);
  return 0;
}