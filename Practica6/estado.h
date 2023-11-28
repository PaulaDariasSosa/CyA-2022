/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo estado.h: declaracion de la clase Estado
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código 
#include "simbolo.h"
#pragma once
class Estado {
 public:
  Estado(std::string actual, Simbolo transicion, std::string destino);
  Estado() {};
  Simbolo transicion() const { return transicion_; }
  std::string Siguiente_estado() const { return Siguiente_estado_; }
  bool es_final() const { return es_final_; }
 private:
  std::string Actual_estado_; /// Nombre del estado en si
  std::string Siguiente_estado_; /// Nombre del siguente estado
  Simbolo transicion_; /// Simbolo con el que se transita
  bool es_final_; ///Booleano que indica si es un estado final, o no
};