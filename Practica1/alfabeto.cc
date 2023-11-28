// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo alfabeto.cc: programa que contiene el desarollo de la clase alfabeto.
// Contiene el desarollo de la clase Alfabeto
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#include "alfabeto.h"

Alfabeto::Alfabeto (std::vector<std::string> alfabeto) {
  for (const auto simbolo_auxuliar : alfabeto) {
  alfabeto_.push_back(Simbolo(simbolo_auxuliar));
  }
}

bool Alfabeto::Buscar_Simbolo(const Simbolo& buscando) {
  for (const auto simbolo : alfabeto_) {
    if (simbolo.caracter() == buscando.caracter()) return true;
  }
  return false;
}


