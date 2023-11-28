// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo simbolo.h: programa que contiene la declaracion de la clase Simbolo.
// Contiene la declaracion de la clase Simbolo, cuyo atributo es un string
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <string>

class Simbolo {
 public:
  Simbolo() {}       
  Simbolo(std::string caracter) : caracter_{caracter} {}; //constructor a partir de string
  Simbolo(const Simbolo& other); // constructor copia
  std::string caracter() const { return caracter_; } // Getter

 private:
  std::string caracter_;
};

bool operator<(Simbolo const& simbol_1, Simbolo const& simbol_2);