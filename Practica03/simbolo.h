// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo simbolo.h: programa que contiene la declaracion de la clase Simbolo.
// Contiene la declaracion de la clase Simbolo, cuyo atributo es un string
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

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