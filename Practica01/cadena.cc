// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo cadena.cc: programa que contiene el desarollo de la clase cadena.
// Contiene el desarollo de la clase Cadena
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#include "cadena.h"
#include <string>
const std::string VACIO{"& "};
const std::string ESPACIO{" "};

Cadena::Cadena(std::string line) {
  std::vector<std::string> alfabeto;
  std::string cadena_auxiliar;
  std::string cadena_palabra;
  int linea_size = line.size();

  for (int i = 0; i < linea_size; ++i) {
    if (line[i] == ' ') {
      alfabeto.push_back(cadena_auxiliar);
      cadena_auxiliar = "";
    }
    else {
      cadena_auxiliar += line[i];
    }
  }

  cadena_palabra = cadena_auxiliar;
  // En el caso en el que el alfabeto no haya sido proporcionado
  if (alfabeto.size() == 0) {
    for (const auto &caracter : cadena_auxiliar) {
      alfabeto.push_back(std::string(1, caracter));
    }
  }
  raiz_ = Alfabeto(alfabeto);

  cadena_auxiliar = "";
  bool existencia;
  for (const auto caracter : cadena_palabra) {
    existencia = false;
    cadena_auxiliar += caracter;
    if (raiz_.Buscar_Simbolo(Simbolo(cadena_auxiliar))) {
      palabra_.push_back(Simbolo(cadena_auxiliar));
      cadena_auxiliar = "";
      existencia = true;
    }
  }

  if (existencia == false) {
    std::cout << "La linea: " << line << " , no es correcta, la cadena no puede ser formada por el alfabeto proporcionado" << std::endl;
    abort();
  }
}

Cadena Cadena::Tamano_Cadena() {
  Simbolo tamano = std::to_string(palabra().size());
  std::vector<Simbolo> retorno;
  retorno.push_back(tamano);
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

Cadena Cadena::Inversa_Cadena() {
  std::vector<Simbolo> retorno;
  for (int i = palabra().size() - 1; i >= 0; --i) {
    retorno.push_back(palabra()[i]);
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

Cadena Cadena::Prejijos() {
  std::vector<Simbolo> retorno;
  retorno.push_back(VACIO);
  std::string uniones;
  for (int i = 0; i < palabra().size(); ++i) {
    Simbolo aux = palabra()[i];
    uniones += aux.caracter();
    retorno.push_back(Simbolo(uniones + ESPACIO));
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

Cadena Cadena::Sufijo() {
  std::vector<Simbolo> retorno;
  retorno.push_back(VACIO);
  std::string uniones;
  for (int i = palabra().size() - 1; i >= 0; --i) {
    std::string cadena_auxiliadora;
    uniones = palabra()[i].caracter() + uniones;
    retorno.push_back(Simbolo(uniones + (" ")));
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

Cadena Cadena::Subcadenas() {
  std::vector<Simbolo> retorno;
  retorno.push_back(VACIO);
  for (int i = 0; i < palabra().size(); ++i) {
    retorno.push_back(Simbolo (palabra()[i].caracter() + (" ")));
    std::string cadena_uniones = palabra()[i].caracter(); 
    for (int j = i + 1; j < palabra().size(); ++j) {
      cadena_uniones += palabra()[j].caracter();
      retorno.push_back(Simbolo (cadena_uniones+ (" ")));
    }
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

std::ostream &operator<<(std::ostream &out, const Cadena &actual) {
  for (int i = 0; i < actual.palabra().size(); ++i) {
    out << actual.palabra()[i].caracter();
  }
  return out;
}
