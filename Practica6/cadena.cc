/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo cadena.cc: desarollo de la clase Cadena
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código

#include "cadena.h"
#include <algorithm>
const std::string VACIO{"& "};
const std::string ESPACIO{" "};

Cadena::Cadena(std::string linea, Alfabeto raiz) {
  bool imposible;
  std::string aux;
  for (long unsigned int i = 0; i < linea.size(); ++i) {
    aux.push_back(linea[i]);
    imposible = true;
    if ((raiz.Buscar_Simbolo(Simbolo(aux))) || (aux == "&")) {
      palabra_.push_back(Simbolo(aux));
      aux.clear();
      imposible = false;
    }
  }
  if (imposible == true) {
    std::cout << "ERROR. Se ha introducido un simbolo que no pertenece a la cadena" << std::endl;
    exit(1); 
  }
}

int Cadena::Tamano_Cadena() {
  return palabra().size();
}

Cadena Cadena::Inversa_Cadena() {
  std::vector<Simbolo> retorno;
  for (long unsigned int i = palabra().size() - 1; i >= 0; --i) {
    retorno.push_back(palabra()[i]);
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

Cadena Cadena::Prejijos() {
  std::vector<Simbolo> retorno;
  retorno.push_back(VACIO);
  std::string uniones;
  for (long unsigned int i = 0; i < palabra().size(); ++i) {
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
  for (long unsigned int i = palabra().size() - 1; i >= 0; --i) {
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
  for (long unsigned int i = 0; i < palabra().size(); ++i) {
    retorno.push_back(Simbolo (palabra()[i].caracter() + (" ")));
    std::string cadena_uniones = palabra()[i].caracter(); 
    for (long unsigned int j = i + 1; j < palabra().size(); ++j) {
      cadena_uniones += palabra()[j].caracter();
      retorno.push_back(Simbolo (cadena_uniones+ (" ")));
    }
  }
  Cadena cadena_retorno = retorno;
  return cadena_retorno;
}

std::ostream &operator<<(std::ostream &out, const Cadena &actual) {
  for (long unsigned int i = 0; i < actual.palabra().size(); ++i) {
    out << actual.palabra()[i].caracter();
  }
  return out;
}
/// Sobrecarga de operador < para la introduccion de cadenas en el set
bool operator<(Cadena const& cadena_1, Cadena const& cadena_2) {
  if (cadena_1 == cadena_2) {
    return false;
  }
  for (long unsigned int i = 0; i < std::max(cadena_1.palabra().size(), cadena_2.palabra().size()); ++i) {
    if (i == cadena_2.palabra().size()) {
      if (cadena_2.palabra().size() == cadena_1.palabra().size()) {
        return false;
      }
      return true;
    }
    if (i == cadena_1.palabra().size()) {
      return false;
    }
    if (cadena_1.palabra()[i].caracter() != cadena_2.palabra()[i].caracter()) {
      bool retorno = cadena_1.palabra()[i].caracter() < cadena_2.palabra()[i].caracter();
      return retorno;
    }
  }
  return true;
}

Cadena operator+(const Cadena& cadena1, const Cadena& cadena2) {
  std::vector<Simbolo> retorno;
  for (long unsigned int i = 0; i < cadena1.palabra().size(); ++i) {
    retorno.push_back(cadena1.palabra()[i]);
  }
  for (long unsigned int i = 0; i < cadena2.palabra().size(); ++i) {
    retorno.push_back(cadena2.palabra()[i]);
  }
  Cadena retorno_cadena = retorno;
  return retorno_cadena;
}
/// Sobrecarga del operador == para la comprobacion de la igualdad de las cadenas
bool operator==(const Cadena& cadena1, const Cadena& cadena2) {
  if (cadena1.palabra().size() != cadena2.palabra().size()) {
    return false;
  }

  for (long unsigned int i = 0; i < cadena1.palabra().size(); ++i) {
    if (cadena1.palabra()[i].caracter() != cadena2.palabra()[i].caracter()) {
      return false;
    }
  }
  
  return true;
}