/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo gramatica.cc: declaracion de la clase Produccion
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código

#include <vector>
#include <string>

#pragma once
class Produccion {
 public:
    Produccion(std::vector<std::string> produccion) : produccion_{produccion} {};
    Produccion() {};
    std::vector<std::string> produccion() const { return produccion_; };
 //private:
  std::vector<std::string> produccion_;
};

bool operator==(const Produccion& p1, const Produccion& p2);

