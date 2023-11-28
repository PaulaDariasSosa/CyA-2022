// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 01/10/2022
// Archivo funciones.cc: programa que contiene las funciones invocadas desde el main.
// Contiene las funciones Usage, que le indica al usuaio como ejecutar el programa, 
//y la funcion Operar_Cadena que realiza una operacion en funcion al opcode solicitado.
// Referencias:
// Historial de revisiones
// 29/09/2022 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include "cadena.h"

const std::string kHelpText = "El programa usa las clases simbolo, cadena e alfabeto \
para identificar las posibles cadenas y alfabetos de un documento de texto e imprimir \
en otro documento, información, de las cadenas, solicitada por el usuario. \
El usuario deberá introducir: ./p01_strings 'El texto de entrada' 'El texto de salida' y el código de operación. \
Los codigos de operacón son: Tamaño(1), Invertir(2), Prefijos(3), Sufijo(4) y Subcadenas(5)";

void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    } 
  } else {
    if (argc != 4) {
      std::cout << argv[0] << ": Faltan parámetros para realizar la operación." << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  
}

Cadena Operar_Cadena(Cadena cadena_actual, int opcode) {
  switch (opcode) {
    case 1: //longitud
      return cadena_actual.Tamano_Cadena();
    break;

    case 2: //inversa
      return cadena_actual.Inversa_Cadena();
    break;

    case 3: //prefijo
      return cadena_actual.Prejijos();
    break;
      
    case 4:  //sujifo 
      return cadena_actual.Sufijo();
    break;

    case 5: 
     return cadena_actual.Subcadenas();
    break;

    default:
      std::cout << "El código de operación debe estar entre 1 y 5, para más información escribir --help" << std::endl;
      abort();
    break;
    }
    //return cadena_retorno;
}
