/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #07: Gramática regular a partir de un DFA
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 14/11/2022
/// Archivo automata.h: declaracion de la clase Automata
/// Referencias:
/// Historial de revisiones
/// 14/11/2022 - Creación (primera versión) del código

#include <vector>
#include "estado.h"
#include "alfabeto.h"
#include "cadena.h"
#include "gramatica.h"
#include <map>
#include <set>


class Automata : Estado {
 public:
  Automata(std::string filename);
  void Probar_Recursivo(std::string automata_entrada);
  Gramatica Pasar_A_Gramatica();
 private:
  std::set<std::string> Comprobar_Estados(std::string automata_entrada); ///comprueba si la estructura del fichero.fa es correcto
  std::vector<std::string> Siguiente_Estado(std::set<std::string> actuales, Simbolo transitor); ///busca los siguientes estados posibles a partir de los actuales y un simbolo
  bool Estado_Existe(std::set<std::string> estados_posibles, std::string estado_a_probar); ///comprueba si el estado introducido ha sido declarado
  bool Estados_Recursivo(std::set<std::string> actuales, Cadena aux, int iterador); ///Calcula los estados a los que se llaga con una cadena de manera recursiva
  void Nombre_Estados(std::map<std::string, std::vector<Estado>> estados, Alfabeto alfabeto);
  void Comprobar_si_DFA();

  std::map<std::string, std::vector<Estado>> estados_; /// un mapa del nombre de los estados junto a un vector de estados
  Alfabeto alfabeto_; /// alfabeto que sigue el automata
  std::vector<std::string> finales_; ///vector con los nombres de los estados finales
  std::string inicial_; /// nombre del estado inicial
  int numero_de_estados_; ///numero de estados totales del autoamata
  int transiciones_totales_;
};
