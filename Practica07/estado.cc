/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo estado.cc: desarollo de la clase Estado
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código
#include "simbolo.h"
#include "estado.h"

Estado::Estado (std::string actual, Simbolo transicion, std::string destino) {
  Actual_estado_ = actual;
  transicion_ = transicion;
  Siguiente_estado_ = destino;
}

Estado::Estado (std::string actual, Simbolo transicion) {
  Actual_estado_ = actual;
  transicion_ = transicion;
}