// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo Analizador.h: declaracion de la clase Analizador
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <iostream>
#include <regex>
#include <vector>
#include <string>

#include "Coincidentes.h"

class Analizador {
 public:
  Analizador(std::string filename);
  void write(std::ostream& output_stream) const;
 
  // Getters
  std::vector <Coincidecias> variables() const { return variables_;}
  std::vector <Coincidecias> bucles() const { return bucles_;}
  std::vector <Coincidecias> comentarios() const { return comentarios_;}
  std::vector <Coincidecias> comentarios_multilinea() const { return comentarios_multilinea_;}
  bool main() const {return main_;}
  bool descripcion() const {return descripcion_;}
  std::string titulo() const {return titulo_;}
  // Escribir fichero
  void Read(std::string kFileName2);

 private: 
  void Caso_Variable (std::string linea_actual, int numero_linea);
  void Caso_Bucle (std::string linea_actual, int numero_linea);
  void Caso_Comentario (std::string linea_actual, int numero_linea);
  void Caso_Comentario_Multilinea (std::string linea_acumulada, int numero_linea_inicio, int numero_linea_final);
  std::vector <Coincidecias> variables_;
  std::vector <Coincidecias> bucles_;
  bool main_;
  bool descripcion_;
  std::vector <Coincidecias> comentarios_;
  std::vector <Coincidecias> comentarios_multilinea_;
  std::string titulo_;
};