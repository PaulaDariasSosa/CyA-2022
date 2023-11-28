// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo simbolo.cc: programa que contiene el desarollo de la clase Simbolo.
// Contiene el desarollo de la clase Simbolo
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

#include <iostream>
#include <vector>
#include <string>
#include "simbolo.h"
// Constructor copia de Simbolo 
Simbolo::Simbolo (const Simbolo& other) {
  caracter_ = other.caracter_; 
}

bool operator<(Simbolo const& simbol_1, Simbolo const& simbol_2) {
  return simbol_1.caracter() < simbol_2.caracter();
}