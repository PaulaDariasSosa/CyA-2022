/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo simbolo.cc: desarollo de la clase Simbolo
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código

#include <vector>
#include "simbolo.h"
/// Constructor copia de Simbolo 
Simbolo::Simbolo (const Simbolo& other) {
  simbolo_ = other.simbolo_; 
}

bool operator<(Simbolo const& simbol_1, Simbolo const& simbol_2) {
  return simbol_1.caracter() < simbol_2.caracter();
}