// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo simbolo.cc: programa que contiene el desarollo de la clase Simbolo.
// Contiene el desarollo de la clase Simbolo
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#include <vector>
#include "simbolo.h"
// Constructor copia de Simbolo 
Simbolo::Simbolo (const Simbolo& other) {
  caracter_ = other.caracter_; 
}

bool operator<(Simbolo const& simbol_1, Simbolo const& simbol_2) {
  return simbol_1.caracter() < simbol_2.caracter();
}