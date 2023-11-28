// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases simbolo, cadena e alfabeto
// para identificar las posibles cadenas y alfabetos de un documento de texto e imprimir
// en otro documento, información, de las cadenas, solicitada por el usuario.
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

//Librerias incluidas
#include <iostream>
#include <fstream>

//Ficheros includos
#include "funciones.cc"
#include "cadena.h"
#include "alfabeto.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::vector<Simbolo> principal;
  std::string line;
  const std::string kFileName1 = argv[1];
  const std::string kFileName2 = argv[2];
  const int opcode = atoi(argv[3]);
  std::ifstream input_file(kFileName1, std::ios_base::in);
  
  std::vector<Cadena> cadenas_extraidas;
  while(getline(input_file, line)) {
    if ((line.size() != 0) && (line !=(" "))) {
      cadenas_extraidas.push_back(Cadena(line)); 
    }
  }
  std::ofstream output_file;
  output_file.open(kFileName2, std::ofstream::out);
  int size = cadenas_extraidas.size();
  for (int i = 0; i < size; ++i) {
    output_file << Operar_Cadena(cadenas_extraidas[i], opcode) << "\n";
  }
  output_file.close();
  return 0;
}