/// Universidad de La Laguna
/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo simbolo.cc: desarollo de la clase Simbolo
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <string>

class Simbolo {
 public:
  Simbolo() {}       
  Simbolo(std::string caracter) : simbolo_{caracter} {}; ///constructor a partir de string
  Simbolo(const Simbolo& other); /// constructor copia
  std::string caracter() const { return simbolo_; } /// Getter

 private:
  std::string simbolo_; ///el simbolo en cuestion
};

bool operator<(Simbolo const& simbol_1, Simbolo const& simbol_2);