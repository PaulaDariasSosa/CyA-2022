// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases simbolo, cadena, alfabeto y lenguaje
// para identificar los posibles lenguajes y sus alfabetos de un documento de texto e imprimir
// en otro documento, operaciones, de los lenguajes, solicitadas por el usuario.
// Se comprime con ( tar cfvz ~/p03_Paula_Darias.tgz ../Practica3/ )
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

//Librerias incluidas
#include <iostream>

//Ficheros includos
#include "funciones.cc"
#include "cadena.h"
#include "alfabeto.h"
#include "lenguaje.h"
#include "calculadora.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kFileName1 = argv[1];
  Calculadora_lenguajes(kFileName1);
  return 0;
}