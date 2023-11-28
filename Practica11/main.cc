/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #11: Algoritmos Voraces (Greedy). Cambio de Monedas
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/12/2022
/// Archivo main.cc: contiene la funcion principal

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include "cambio.h" 
#include "utilidades.h"

  
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  float cantidad;
  bool billetes = false;
  bool optimo = false;
  if (argc == 2) {
    cantidad = atof(argv[1]);
  }
  if (argc == 3) {
    const std::string kArgumento1 = argv[1];
    cantidad = atof(argv[2]);
    if (kArgumento1 == "-b") {
      billetes = true;
    }
    if (kArgumento1 == "-o") {
      optimo = true;
    }
  }
  if (argc == 4) {
    const std::string kArgumento1 = argv[1];
    const std::string kArgumento2 = argv[2];
    cantidad = atof(argv[3]);
    if ((kArgumento1 == "-b") || (kArgumento2 == "-b")) {
      billetes = true;
    }
    if ((kArgumento1 == "-o") || (kArgumento2 == "-o")) {
      optimo = true;
    }
  }
  Cambio resultado;
  if (optimo == false) {
    resultado = devolver_cambio(cantidad, billetes);
  } else {
    resultado = devolver_optimo(cantidad, billetes);
  }
  
  std::cout << "Solución: " << resultado << std::endl;
}