// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo funciones.cc: programa que contiene la funcion Usage
// Contiene las funciones Usage, que le indica al usuaio como ejecutar el programa,
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#include "funciones.h"

//Funcion para indicarle al usuario como usar el programa
void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    } 
  } 
  if (argc != 2) {
    std::cout << argv[0] << ": Faltan parámetros para realizar la operación." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}



