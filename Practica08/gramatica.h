/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo gramatica.h: delcaracion de la clase Gramatica
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código

#include "alfabeto.h"
#include "producciones.h"
#include <set>
#include <map>
#include <vector>

#pragma once

class Gramatica {
 public:
  Gramatica() {};
  Gramatica(std::string filename);
  void Imprimir(std::string kFileName);
  /// Getter
  Alfabeto alfabeto() const { return Simbolos_Terminales_; }
  std::string Simbolo_Arranque() const { return Simbolo_Arranque_; } 
  std::set<std::string> Simbolos_No_Terminales() const { return Simbolos_No_Terminales_; };
  std::map<std::string, std::vector<Produccion>> producciones() const { return producciones_; };
  /// Setters
  void setAlfabeto(Alfabeto nuevo) { Simbolos_Terminales_ = nuevo;}
  void setSimbolo_Arranque(std::string nuevo) {Simbolo_Arranque_ = nuevo;}
  void Simbolos_No_Terminales(std::set<std::string> nuevo) {Simbolos_No_Terminales_ = nuevo;}
  void setproducciones(std::map<std::string, std::vector<Produccion>> nuevo) {producciones_ = nuevo;}
  ///Funciones
  void Add_Produccion(std::string Nombre, std::vector<Produccion> nueva_produccion);
  bool Produccion_Existe(std::set<std::string> estados_posibles, std::string estado_a_probar);
  void Pasar_FN();
  bool Produccion_Igual (std::map<std::string, std::vector<Produccion>> producciones, Produccion p1);
  std::string Nombre_Igual (std::map<std::string, std::vector<Produccion>> producciones, Produccion p1);
 /// Atributos
 private:
  std::set<std::string> Simbolos_No_Terminales_;
  std::string Simbolo_Arranque_;
  std::map<std::string, std::vector<Produccion>> producciones_;
  Alfabeto Simbolos_Terminales_;
};