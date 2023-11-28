// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo lenguaje.h: programa que contiene la declaracion de la clase Lenguaje.
// Contiene la declaracion de la clase Lenguaje, cuyos atributo son un set de Cadenas y un Alfabeto
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "alfabeto.h"
#include "cadena.h"

#ifndef LANGUAGE_H_
#define LANGUAGE_H_
class Lenguaje {
 public:
  Lenguaje () {}
  Lenguaje(std::string line);      
  Lenguaje(std::set<Cadena> lenguaje) : lenguaje_{lenguaje} { ///constructor por parametros
    //std::cout << "Ejecutado el constructor con parámetros de Cadena." << std::endl;
  }
  Lenguaje (const Lenguaje& otro); // constructor copia
  std::set<Cadena> lenguaje() const { return lenguaje_; } // Getter del set del lenguaje
  Alfabeto raiz() const { return raiz_; } // Getter del alfabeto del lenguaje
  friend std::ostream& operator<<(std::ostream& out, const Lenguaje& actual);
  Lenguaje Concatenacion(const Lenguaje& lenguaje2);
  Lenguaje Union(const Lenguaje& lenguaje2);
  Lenguaje Interseccion(const Lenguaje& lenguaje2);
  Lenguaje Diferencia(const Lenguaje& lenguaje2);
  Lenguaje Potencia(int iteraciones);
  Lenguaje Inversa();
  
 private:
  std::set<Cadena> lenguaje_;
  Alfabeto raiz_;
};
// La sobrecarga de operadores para facilitar el uso de las operaciones
Lenguaje operator+(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2);
Lenguaje operator|(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2);
Lenguaje operator^(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2);
Lenguaje operator-(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2);
Lenguaje operator!(const Lenguaje& lenguaje1);
Lenguaje operator*(const Lenguaje& lenguaje1, int iteraciones);

#endif
