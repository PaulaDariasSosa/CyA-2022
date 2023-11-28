// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo alfabeto.h: programa que contiene la declaracion de la clase Alfabeto.
// Contiene la declaracion de la clase Alfabeto, cuyo atributo es un set de Simbolos
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#pragma once 

#include "simbolo.h"
#include <set>

class Alfabeto {
 public:   
  Alfabeto () {}
  Alfabeto(std::set<std::string> alfabeto);
  Alfabeto(const Alfabeto& otro); //constructor copia
  std::set<Simbolo> alfabeto() const { return alfabeto_; } // Getter
  bool Buscar_Simbolo(const Simbolo& buscando);
  Alfabeto operator+(const Alfabeto& alfabeto1);
  Alfabeto Interseccion(const Alfabeto& alfabeto1);
  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& actual);
  
 private:
  std::set<Simbolo> alfabeto_;
};


