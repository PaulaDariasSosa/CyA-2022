// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo cadena.h: programa que contiene la declaracion de la clase Cadena.
// Contiene la declaracion de la clase Cadena, cuyos atributos son un vector de Simbolos y un alfabeto
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "alfabeto.h"

class Cadena : public Simbolo{
 public:
  Cadena () {}
  Cadena(std::string line);      
  Cadena(std::vector<Simbolo> palabra) : palabra_{palabra} { ///constructor por parametros
    //std::cout << "Ejecutado el constructor con parámetros de Cadena." << std::endl;

  }
  std::vector<Simbolo> palabra() const { return palabra_; } // Getter
  Alfabeto raiz() const { return raiz_; }
  //std::string Operar_cadena(int opcode);
  Cadena Tamano_Cadena();
  Cadena Inversa_Cadena();
  Cadena Prejijos();
  Cadena Sufijo();
  Cadena Subcadenas();
  friend std::ostream& operator<<(std::ostream& out, const Cadena& actual);

 private:
  std::vector<Simbolo> palabra_;
  Alfabeto raiz_;
};

