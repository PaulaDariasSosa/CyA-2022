// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo Coincidecias.cc: desarollo de la clase Coincidecias
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <string>
#include "Coincidentes.h"

Coincidecias::Coincidecias(int starting_line, int ending_line, Type type, std::string info) {
  inicio_ = starting_line;
  final_ = ending_line;
  tipo_ = type;
  info_ = info;
}

std::ostream& operator<<(std::ostream& out, const Coincidecias& actual) {
  int tipo_coincidencia = actual.tipo();
  switch (tipo_coincidencia) {
    case (1) : {
      out << "[Line " << actual.inicio() << "] " << actual.info(); // sustituir int o double a mayuscula
    }
    break;
    case (2) : {
      out << "[Line " << actual.inicio() << "] " << "LOOP: " << actual.info();
    }
    break;
    case (3) : {
      out << "[Line " << actual.inicio() << "] " << actual.info();
    }
    break;
    case (4) : {
      out << "[Line " << actual.inicio() << " - " << actual.final() << "] " << actual.info();
    }
    break;
  }
  return out;
}