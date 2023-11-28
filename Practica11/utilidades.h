/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #11: Algoritmos Voraces (Greedy). Cambio de Monedas
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/12/2022
/// Archivo utillidades.h: declaracion de las funciones usadas.

#include <iostream>
#include "cambio.h" 

const std::string kHelpText = "El programa proporciona el numero y el tipo de monedas minimo para N cantidad\
introducido por linea de comandos por el usuario, del modo: 'ejecutable' 'cantidad'. Si se introduce\
la opcion -b antes de la cantidad se consideraran no solo el conjunto de monedas de curso legal en la Eurozona, sino\
tambien los billetes. Tambien se dispone de la opcion -o, que utilizara el algoritmo alternativo (mas optimo), ambas opciones\
pueden usarse juntas.";

void Usage(int argc, char *argv[]);

Cambio devolver_cambio (float cantidad, bool billetes);

Cambio devolver_optimo(float cantidad, bool billetes);
