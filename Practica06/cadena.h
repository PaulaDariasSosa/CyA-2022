/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo cadena.h: declaracion de la clase Cadena
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código

#pragma once
#include <vector>
#include "alfabeto.h"

class Cadena : public Simbolo{
 public:
  Cadena () {}   
  Cadena(std::vector<Simbolo> palabra) : palabra_{palabra} { ////constructor por parametros
    ///std::cout << "Ejecutado el constructor con parámetros de Cadena." << std::endl;
  }
  Cadena(std::string linea, Alfabeto raiz);
  std::vector<Simbolo> palabra() const { return palabra_; } /// Getter
  Alfabeto raiz() const { return raiz_; }
  int Tamano_Cadena();
  Cadena Inversa_Cadena();
  Cadena Prejijos();
  Cadena Sufijo();
  Cadena Subcadenas();
  Alfabeto Modificacion();
  friend std::ostream& operator<<(std::ostream& out, const Cadena& actual);
  
 private:
  std::vector<Simbolo> palabra_; ///la cadena en si
  Alfabeto raiz_; ///alfabeto con el que se forma la cadena
};
Cadena operator+(const Cadena& cadena1, const Cadena& cadena2);
bool operator<(Cadena const& cadena_1, Cadena const& cadena_2);
bool operator==(Cadena const& cadena_1, Cadena const& cadena_2);