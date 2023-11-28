// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo alfabeto.h: programa que contiene la declaracion de la clase Alfabeto.
// Contiene la declaracion de la clase Alfabeto, cuyo atributo es un vector de Simbolos
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include "simbolo.h"

class Alfabeto {
 public:   
  Alfabeto () {}
  Alfabeto(std::vector<std::string> alfabeto);
  std::vector<Simbolo> alfabeto() const { return alfabeto_; } // Getter
  bool Buscar_Simbolo(const Simbolo& buscando);
 private:
  std::vector<Simbolo> alfabeto_;
};


