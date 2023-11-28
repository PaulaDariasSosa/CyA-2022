/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #11: Algoritmos Voraces (Greedy). Cambio de Monedas
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/12/2022
/// Archivo utillidades.cc: desarollo de las funciones usadas.

#include "utilidades.h"
#include <cmath>

/**
 * @brief: Funcion para mostrar mensaje de error o mensaje de ayuda al usuario
*/

void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    } 
  } 
  if (argc < 2) {
    std::cout << argv[0] << ": Faltan parámetros para realizar la operación." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief: funcion para buscar la cantidad de monedas(y billetes) necesarias para N cantidad
*/

Cambio devolver_cambio (float cantidad, bool billetes) {
  std::vector<float> M;
  if (billetes == true) {
    M = { 200, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01 }; // lista de monedas (y billetes)
  } else {
    M = { 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01 };
  }
  std::vector<std::pair<dinero, int>> S;     // conjunto de la solución // vector de cambios
  float suma = 0;  // suma de los elementos de S // float o double
  long unsigned int indice = 0;
  while (cantidad - suma > 0.0001f ) { // mientras no se haya llegado a la c0natidad pedida
    float v = 0; // metemos en v el mayor elemento de M que suma + v sea <= a n // esto es o complicado
    // v<- mayor elemento de M tal que suma + v <= n
    float aux = M[indice];
    if ((cantidad - (suma + aux) > -0.001f)) { // cantidad - (suma + aux) > 0.001f
    // 0.34, 0,34 - 0,2; 0,34 - 0,2 + 0,3; 0,34 - 0,32 + 0,02 = 0,000 > 0,001
      v = aux;
    }
    if (v == 0){ // sino existe (todos son muy grandes) sacar error
      if (indice == M.size()) {
        abort(); // sacar error
      }
      ++indice;
    } else {
      //S.push_back(dinero(v)); // metemos en S la moneda (o billete) seleccionado
      if (!S.empty() && (v == S.back().first.get_valor())) {
        S.back().second += 1;
      } else {
        S.push_back(std::make_pair(dinero(v), 1));
      }
      suma = suma + v;// a suma le sumamos el valor almacenado en v
    }
    
  }
  return Cambio(S); // devolvemos el conjunto final
}

/**
 * @brief: funcion para buscar la cantidad de monedas(y billetes) necesarias para N cantidad
 * @bug: si no se le realiza un ajuste la solucion dada no sera correcta
*/

Cambio devolver_optimo(float cantidad, bool billetes) {
  std::list<float> M;
  if (billetes == true) {
    M = { 500, 200, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01 }; // lista de monedas (y billetes)
  } else {
    M = { 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01 };
  }
  std::vector<std::pair<dinero, int>> S;     // conjunto de la solución // vector de cambio
  float suma = 0;  // suma de los elementos de S // float o double
  for (auto v : M) { //para v ∈ M (de mayor a menor valor) hacer {
    int c = (cantidad - suma + 0.000025f) / v; //c <- (n - suma) / v  // división entera // el valor decimal ajusta el algoritmo para que no falle
    // sino se realiza un ajuste en algunos casos la division dara 0.999925 y no contara la moneda aunque sea lo correscto y necesario
    if (c > 0) { //si c > 0 entonces 
      S.push_back(std::make_pair(dinero(v), c));
      suma = suma + c*v;// suma <- suma + c * v
    } 
  }
  return Cambio(S); //devolver S
}