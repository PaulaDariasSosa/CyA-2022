// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo cadena.h: programa que contiene la declaracion de la clase Cadena.
// Contiene la declaracion de la clase Cadena, cuyos atributos son un vector de Simbolos y un alfabeto
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "alfabeto.h"

class Cadena : public Simbolo{
 public:
  Cadena () {}   
  Cadena(std::vector<Simbolo> palabra) : palabra_{palabra} { ///constructor por parametros
    //std::cout << "Ejecutado el constructor con parámetros de Cadena." << std::endl;
  }
  std::vector<Simbolo> palabra() const { return palabra_; } // Getter
  Alfabeto raiz() const { return raiz_; }
  Cadena Tamano_Cadena();
  Cadena Inversa_Cadena();
  Cadena Prejijos();
  Cadena Sufijo();
  Cadena Subcadenas();
  Alfabeto Modificacion();
  friend std::ostream& operator<<(std::ostream& out, const Cadena& actual);
  
 private:
  std::vector<Simbolo> palabra_;
  Alfabeto raiz_;
};
Cadena operator+(const Cadena& cadena1, const Cadena& cadena2);
bool operator<(Cadena const& cadena_1, Cadena const& cadena_2);
bool operator==(Cadena const& cadena_1, Cadena const& cadena_2);