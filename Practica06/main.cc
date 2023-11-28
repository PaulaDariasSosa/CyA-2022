/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo main.cc: funcion principal
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código
/// Se compila con: tar cfvz ~/p06_Paula_Darias.tgz ../Practica6/
#include <fstream>
#include <iostream>
#include "funciones.h"
#include "automata.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kFileName1 = argv[1];
  std::string kFileName2 = argv[2];
  Automata prueba (kFileName1);
  prueba.Probar_Recursivo(kFileName2);
  return 0;
}