// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo simbolo.cc: programa que contiene el desarollo de la clase Simbolo.
// Contiene el desarollo de la clase Simbolo
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#include <iostream>
#include <vector>
#include <string>
#include "simbolo.h"

Simbolo::Simbolo (const Simbolo& other) {
  caracter_ = other.caracter_; 
}