/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #11: Algoritmos Voraces (Greedy). Cambio de Monedas
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/12/2022
/// Archivo cambio.cc: desarollo de la clase cambio.

#include <iostream> 
#include "cambio.h"

/**
 * @brief: constructor de la clase Cambio
*/

Cambio::Cambio(std::vector<std::pair<dinero, int>> cambio) {
  cambio_ = cambio;
}

/**
 * @brief: sobrecarga del operador de inserccion
*/

std::ostream &operator<<(std::ostream &out, const Cambio &actual) {
  int contador_dinero = 0;
  for (auto aux : actual.get_Cambio()) {
    if (aux.second != 1) std::cout << aux.second << "x";
    if (aux.first.get_valor() >= 1) out << aux.first.get_valor() << "€, ";
    else out << aux.first.get_valor()*100 << "¢, ";
    contador_dinero += aux.second;
  }
  out << "\n" << "Total de monedas: " << contador_dinero;
  return out;
}