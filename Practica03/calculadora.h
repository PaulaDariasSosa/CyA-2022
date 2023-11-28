// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo calculadora.h: contiene las declaraciones de funciones necesarias para realizar la actividad.
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#include <fstream>
#include <stack>
#include <map>
#include <cctype>
#include "lenguaje.h"

bool Operandos_en_pila (std::stack<Lenguaje> operaciones, int necesarios);
bool Posible_Lenguaje (std::string line);
void Calculadora_lenguajes (std::string kFileName);