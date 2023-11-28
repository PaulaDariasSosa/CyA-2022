/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo funciones.h: declaracion de la funcion Usage y del texto de ayuda
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código


#include <fstream>
#include <iostream>
#include <string>

const std::string kHelpText = "El programa usa las clases Analizador y coincidecias para analizar \
un documento de codigo. Para su ejecucion use ./nombre_ejecutable archivo_entrada archivo_salida";

void Usage(int argc, char *argv[]);