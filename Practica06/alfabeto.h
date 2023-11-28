/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo alfabeto.h: delcaracion de la clase Alfabeto
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código

#pragma once 

#include "simbolo.h"
#include <set>

class Alfabeto {
 public:   
  Alfabeto () {}
  Alfabeto(std::set<std::string> alfabeto);
  Alfabeto(const Alfabeto& otro); ///constructor copia
  std::set<Simbolo> alfabeto() const { return alfabeto_; } /// Getter
  bool Buscar_Simbolo(const Simbolo& buscando);
  Alfabeto operator+(const Alfabeto& alfabeto1);
  Alfabeto Interseccion(const Alfabeto& alfabeto1);
  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& actual);
  
 private:
  std::set<Simbolo> alfabeto_; ///conjunto de simbolos que forman el alfabeto
};


