// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases Buscador y Coincidecias para
// analizar un fichero de codigo y extraer sus variables, bucles y comentarios.
// Se comprime con ( tar cfvz ~/p04_Paula_Darias.tgz ../Practica4/ )
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include "funciones.h"
#include "Analizador.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kFileName1 = argv[1];
  std::string kFileName2 = argv[2];
  Analizador texto_prueba (kFileName1);
  texto_prueba.Read(kFileName2);
  return 0;
}