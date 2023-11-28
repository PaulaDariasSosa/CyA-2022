/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo gramatica.cc: desarollo de la clase Produccion
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código

#include "producciones.h"

/**
 * @brief Sobrecarga del operador de igualdad para producciones
 * @return true o false
*/

bool operator==(const Produccion& p1, const Produccion& p2) {
  if (p1.produccion().size() != p2.produccion().size()) {
    return false;
  }
  for (long unsigned int i = 0; i < p1.produccion().size(); ++i) {
    if (p1.produccion()[i] != p2.produccion()[i]) {
      return false;
    }
  }
  return true;
}