// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 12/10/2022
// Archivo funciones.cc: programa que contiene las funciones invocadas desde el main.
// Contiene las funciones Usage, que le indica al usuaio como ejecutar el programa, 
// la funcion Operar_Cadena que realiza una operacion en funcion al opcode solicitado, 
// ademas de las funciones para extraer lenguajes, imprimirlos y llamar a funciones para realizar operaciones.
// Referencias:
// Historial de revisiones
// 09/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <string>
#include "cadena.h"
#include "lenguaje.h"

const std::string kHelpText = "El programa usa las clases simbolo, cadena, alfabeto y lenguaje \
para identificar los posibles lenguajes y sus alfabetos de un documento de texto e imprimir \
en otro documento, operaciones, de los lenguajes, solicitadas por el usuario. \
El usuario deberá introducir: ./p02_languajes 'El primer texto de entrada' 'El segundo texto de entrada' 'EL texto de salida' \
y el código de operación. Los codigos de operacón son: Concatenacion(1), Union(2), Interseccion(3), Diferencia(4), Inversa(5) y Potencia(6). \
Para escribir el lenguaje vacio es necesario dejar un espacio entre las llaves.";


//Funcion para indicarle al usuario como usar el programa
void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    } 
  } 
  if (argc != 5) {
    std::cout << argv[0] << ": Faltan parámetros para realizar la operación." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
// Funcion para la extraccion de cadenas a partir de un fichero de texto
std::vector<Lenguaje> Extraer_lenguajes (const std::string& kFileName) {
  std::ifstream input_file1(kFileName, std::ios_base::in);
  std::string line;
  std::vector<Lenguaje> lenguajes_extraidos;
  while(getline(input_file1, line)) {
    if ((line.size() != 0) && (line !=(" "))) { //Evitamos los casos donde el usuario para lineas vacias
      lenguajes_extraidos.push_back(Lenguaje(line)); 
    }
  }
  return lenguajes_extraidos;
}
//Funcion para analizar el opcode y llamar a la correspondiente operacion en las cadenas
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
    case 5: //Subcadena
     return cadena_actual.Subcadenas();
    break;
    default:
      std::cout << "El código de operación debe estar entre 1 y 5, para más información escribir --help" << std::endl;
      exit(EXIT_FAILURE);;
    break;
  }
}
//Funcion para analizar el opcode y llamar a la correspondiente operacion en los lenguajes
std::vector<Lenguaje> Operar_lenguaje (std::vector<Lenguaje> l1, std::vector<Lenguaje> l2, int opcode) {
  if ((l1.size() != l2.size())&&(opcode < 5)&&(opcode > 0)) {
    std::cout << "Para realizar la operacion se necesita el mismo numero de lenguajes en ambos ficheros de entrada" << std::endl;
  }
  std::vector<Lenguaje> resultados;
  switch (opcode) {
    case 1: //Concatenación
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back(l1[i]+l2[i]);
      }
      return resultados;
    break;
    case 2: //Unión
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back(l1[i]|l2[i]);
      }
      return resultados;
    break;
    case 3: //Intersección
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back(l1[i]^l2[i]);
      }
      return resultados;
    break; 
    case 4:  //Diferencia 
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back(l1[i]-l2[i]);
      }
      return resultados;
    break;
    case 5: //Inversa
      for (int i = 0; i < l1.size(); ++i) {
        resultados.push_back(!(l1[i]));
      }
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back(!(l2[i]));
      }
      return resultados;
    break;
    case 6: //Potencia
      int iteraciones;
      std::cout << "Introduzca el numero al que desea elevar los lenguajes : " << std::endl;
      std::cin >> iteraciones;
      for (int i = 0; i < l1.size(); ++i) {
        resultados.push_back((l1[i])*(iteraciones));
      }
      for (int i = 0; i < l2.size(); ++i) {
        resultados.push_back((l2[i])*(iteraciones));
      }
      return resultados;
    break;
    default:
      std::cout << "El código de operación debe estar entre 1 y 6, para más información escribir --help" << std::endl;
      exit(EXIT_FAILURE);
    break;
  }
}
// Funcion para imprimir el vector de los lenguajes resultantes en un fichero de salida
void Imprimir_lenguajes(const std::vector<Lenguaje>& resultados, const std::string& kFileName3) {
  std::ofstream output_file;
  output_file.open(kFileName3, std::ofstream::out); //abrimos el fichero de salida
  for (int i = 0; i < resultados.size(); ++i) {
    output_file << resultados[i] << "\n";
  }
  output_file.close();
}
