/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo gramatica.h: delcaracion de la clase Gramatica
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código

#include "estado.h"
#include "alfabeto.h"
#include <set>
#include <map>
#include <vector>

#pragma once

class Gramatica {
 public:
  Gramatica() {};
  void Imprimir(std::string kFileName);
  /// Getter
  Alfabeto alfabeto() const { return Simbolos_Terminales_; }
  std::string Simbolo_Arranque() const { return Simbolo_Arranque_; } 
  std::set<std::string> Simbolos_No_Terminales() const { return Simbolos_No_Terminales_; };
  std::map<std::string, std::vector<Estado>> producciones() const { return producciones_; };
  /// Setters
  void setAlfabeto(Alfabeto nuevo) { Simbolos_Terminales_ = nuevo;}
  void setSimbolo_Arranque(std::string nuevo) {Simbolo_Arranque_ = nuevo;}
  void Simbolos_No_Terminales(std::set<std::string> nuevo) {Simbolos_No_Terminales_ = nuevo;}
  void setproducciones(std::map<std::string, std::vector<Estado>> nuevo) {producciones_ = nuevo;}
 /// Atributo
 private:
  std::set<std::string> Simbolos_No_Terminales_;
  std::string Simbolo_Arranque_;
  std::map<std::string, std::vector<Estado>> producciones_;
  Alfabeto Simbolos_Terminales_;
};