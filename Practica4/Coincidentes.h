// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo Coincidecias.h: declaracion de la clase Coincidecias
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <string>
#pragma once
enum Type {
  variable,
  bucles,
  comentarios,
  comentarios_multilinea,
  sin_tipo
};

class Coincidecias {
 public:
  Coincidecias();
  Coincidecias(int starting_line, int ending_line, Type type, std::string info);
  // Getters
  std::string info() const { return info_; }
  int inicio() const { return inicio_; }
  int final() const { return final_; }
  Type tipo() const { return tipo_; }
  // Lectura de coincidencia
  friend std::ostream& operator<<(std::ostream& out, const Coincidecias& actual);
  void Lectura_Variable();
 private:
  int inicio_;
  int final_;
  Type tipo_;
  std::string info_;
};