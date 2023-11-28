// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases simbolo, cadena, alfabeto y lenguaje
// para identificar los posibles lenguajes y sus alfabetos de un documento de texto e imprimir
// en otro documento, operaciones, de los lenguajes, solicitadas por el usuario.
// Se comprime con ( tar cfvz p02_Paula_Darias.tgz ../Practica2 )
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

//Librerias incluidas
#include <iostream>
#include <fstream>

//Ficheros includos
#include "funciones.cc"
#include "cadena.h"
#include "alfabeto.h"
#include "lenguaje.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string line;
  const std::string kFileName1 = argv[1];
  const std::string kFileName2 = argv[2];
  const std::string kFileName3 = argv[3];
  const int opcode = atoi(argv[4]);
  // Abrimos los ficheros de entrada
  // Extraemos el contenido de los ficheros y lo almacenamos en dos vectores diferentes, para asi saber cuantos lenguajes habia en cada fichero
  std::vector<Lenguaje> lenguajes_extraidos_1 = Extraer_lenguajes(kFileName1);
  std::vector<Lenguaje> lenguajes_extraidos_2 = Extraer_lenguajes(kFileName2);
  // Operamos los lenguajes y los introducimos en un vector
  std::vector<Lenguaje> resultados = Operar_lenguaje(lenguajes_extraidos_1, lenguajes_extraidos_2, opcode);
  // Imprimimos en el archivo de texto de salida los lenguajes resultantes
  Imprimir_lenguajes(resultados, kFileName3);
  return 0;
}