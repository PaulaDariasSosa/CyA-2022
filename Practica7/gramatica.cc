/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo gramatica.cc: desarollo de la clase Gramatica
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código

#include "gramatica.h"
#include <fstream>

/**
 * @brief Imprime la gramatica en el documento dado
*/

void Gramatica::Imprimir(std::string kFileName) {
  std::ofstream output_file;
  output_file.open(kFileName, std::ofstream::out);
  output_file << Simbolos_Terminales_.alfabeto().size() << std::endl;
  for (auto simbolo : Simbolos_Terminales_.alfabeto()) {
    output_file << simbolo.caracter() << std::endl;
  }
  output_file << Simbolos_No_Terminales_.size() << std::endl;
  for (auto simbolo : Simbolos_No_Terminales_) {
    output_file << simbolo << std::endl;
  }
  output_file << Simbolo_Arranque_ << std::endl;
  int contador_prduccion = 0;
  for (auto estado : producciones_) {
    for (auto simbolo_estado : estado.second) {
      ++contador_prduccion;
    }
  }
  output_file << contador_prduccion << std::endl;
  for (auto estado : producciones_) {
    output_file << estado.first << " -> ";
    for (long unsigned int i = 0; i < estado.second.size(); ++i) {
      output_file << estado.second[i].transicion().caracter() << estado.second[i].Siguiente_estado();
      if (i != estado.second.size() - 1) {
        output_file << " | ";
      }
    }
    output_file << std::endl;
  }
}