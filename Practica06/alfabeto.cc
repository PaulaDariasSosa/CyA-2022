/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo alfabeto.cc: desarollo de la clase Alfabeto
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código

#include "alfabeto.h"

/// Constructor a partir de un set de string
Alfabeto::Alfabeto (std::set<std::string> alfabeto) {
  for (const auto simbolo_auxuliar : alfabeto) {
  alfabeto_.insert(Simbolo(simbolo_auxuliar));
  }
}
/// Constructor de copia
Alfabeto::Alfabeto(const Alfabeto& otro) {
  alfabeto_.clear();
  for (auto simbolo_aux : otro.alfabeto()) {
    alfabeto_.insert(simbolo_aux);
  }
}
/// Funcion para comprobar si un simblo pertenece a un alfabeto
bool Alfabeto::Buscar_Simbolo(const Simbolo& buscando) {
  for (const auto simbolo : alfabeto_) {
    if (simbolo.caracter() == buscando.caracter()) {
      return true;
    }
  }
  return false;
}
/// Sobrecarga del operador de inserccion
std::ostream &operator<<(std::ostream &out, const Alfabeto &actual) {
  out << "{";
  for (auto simbolo : actual.alfabeto()) {
    out << " " << simbolo.caracter();
  }
  out << " }";
  return out;
}
/// Sobrecarga del operador suma para sumar alfabetos
Alfabeto Alfabeto::operator+(const Alfabeto& alfabeto1) {
  std::set<std::string> nuevo_alfabeto;
  for (auto caracter: alfabeto()) {
    nuevo_alfabeto.insert(caracter.caracter());
  }
  for (auto caracter: alfabeto1.alfabeto()) {
    nuevo_alfabeto.insert(caracter.caracter());
  }
  return Alfabeto(nuevo_alfabeto);
}
/// Interseccion de los alfabetos
Alfabeto Alfabeto::Interseccion(const Alfabeto& alfabeto1) {
  std::set<std::string> nuevo_alfabeto;
  for (auto caracter1: alfabeto()) {
    for (auto caracter2: alfabeto1.alfabeto()) {
      if (caracter1.caracter()==caracter2.caracter()) {
        nuevo_alfabeto.insert(caracter1.caracter());
      }
    }
  }
  return Alfabeto(nuevo_alfabeto);
}