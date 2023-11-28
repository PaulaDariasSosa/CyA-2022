/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #11: Algoritmos Voraces (Greedy). Cambio de Monedas
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/12/2022
/// Archivo cambio.h: declaracion de la clase cambio.

#include <vector>
#include <ostream>
#include "dinero.h"

#ifndef CAMBIO_H_
#define CAMBIO_H_

class Cambio {
 public:
  Cambio () {};
  Cambio(std::vector<std::pair<dinero, int>> cambio);
  std::vector<std::pair<dinero, int>> get_Cambio() const { return cambio_;}
  void set_Cambio(std::vector<std::pair<dinero, int>> cambio) {cambio_ = cambio;}
  friend std::ostream& operator<<(std::ostream& out, const Cambio& actual);
 private:
  std::vector<std::pair<dinero, int>> cambio_;
};

#endif
