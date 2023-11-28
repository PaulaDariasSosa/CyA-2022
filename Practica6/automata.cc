/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Simulación de autómatas finitos
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 08/11/2022
/// Archivo automata.cc: desarollo de la clase Automata
/// Referencias:
/// Historial de revisiones
/// 07/11/2022 - Creación (primera versión) del código

#include <vector>
#include <fstream>
#include "estado.h"
#include "alfabeto.h"
#include "cadena.h"
#include "automata.h"

Automata::Automata (std::string filename) {
  std::set<std::string> estados_posibles = Comprobar_Estados(filename);
  std::ifstream input_file(filename);
  std::string line;
  std::set<std::string> alfabeto;
  getline(input_file, line);
  for (long unsigned int i = 0; i < line.size(); ++i) {
    std::string aux;
    while ((line[i] != ' ') && (i < line.size()) ) {
      aux.push_back(line[i]);
      ++i;
    }
    if (aux != "") {
      alfabeto.insert(aux);
    }
  } 
  alfabeto_ = alfabeto;
  getline(input_file, line);
  numero_de_estados_ = stoi(line);
  getline(input_file, line);
  inicial_ = line;
  for (int i = 0; i < numero_de_estados_; ++i) {
    getline(input_file, line);
    for (long unsigned int j = 0; j < line.size(); ++j) {
      std::string nombre_estado;
      while (line[j] != ' ') {
        nombre_estado.push_back(line[j]);
        ++j;
      }
      if (line[j] == ' ') {
        ++j; /// para saltarnos el espacio
      } else {
        std::cout << "ERROR en el formato de fichero" << std::endl;
      }
      
      std::string final;
      final.push_back(line[j]);
      bool aceptar = stoi(final);
      if (aceptar == 1) {
        finales_.push_back(nombre_estado); 
      }
      ++j;
      if (line[j] == ' ') {
        ++j; /// para saltarnos el espacio
      } else {
        std::cout << "ERROR en el formato de fichero" << std::endl;
      }
      std::string numero_trans;
      
      while (line[j] != ' ') {
        numero_trans.push_back(line[j]);
        ++j;
      }
      int numero_transiciones = stoi(numero_trans);
      if (line[j] == ' ') {
        ++j; /// para saltarnos el espacio
      } else {
        std::cout << "ERROR en el formato de fichero" << std::endl;
      }
      std::vector<Estado> totales;
      while (numero_transiciones != 0) {
        std::string posible_simbolo;
        while (line[j] != ' ') {
          posible_simbolo.push_back(line[j]);
          ++j;
        }
          ++j; /// para saltarnos el espacio
        Simbolo transicion = posible_simbolo;
        std::string estado_destino;
        while ((line[j] != ' ') && (j < line.size())) {
          estado_destino.push_back(line[j]);
          ++j;
        }
        if (Estado_Existe(estados_posibles, estado_destino)) {
          Estado aux(nombre_estado, transicion, estado_destino);
          totales.push_back(aux);
          if (line[j] == ' ') {
            ++j;
          }
          --numero_transiciones;
        } else {
          std::cout << "ERROR. Se intenta transitar a un estado que no pertenece al automata" << std::endl;
          std::cout << "ERROR en la linea " << line << std::endl;
          exit(1);
        }
        
      }
      estados_.insert_or_assign(nombre_estado, totales);
    }
  }
}

std::vector<std::string> Automata::Siguiente_Estado(std::set<std::string> actuales, Simbolo transitor){
  std::vector<std::string> retorno;
  for (auto actual: actuales) {
    if (estados_.count(actual)) { /// si el elemento ya tiene una declaracion 
      auto buscar = estados_.find(actual);
      std::vector<Estado> aux = (buscar->second);
      for (long unsigned int i = 0; i < aux.size(); ++i) {
        if (aux[i].transicion().caracter() == transitor.caracter()) {
        retorno.push_back(aux[i].Siguiente_estado());
        }
      }
    }
  }
   
  return retorno;
}

bool Automata::Estado_Existe(std::set<std::string> estados_posibles, std::string estado_a_probar) {
  bool existencia = false;
  for (auto estado_actual : estados_posibles) {
    if (estado_actual == estado_a_probar) {
      existencia = true;
    }
  }
  return existencia;
}

std::set<std::string> Automata::Comprobar_Estados(std::string automata_entrada){
  std::ifstream input_file(automata_entrada);
  int contador = 0;
  std::set<std::string> retorno;
  std::string line;
  long unsigned int numero_estados;
  while(getline(input_file, line)) {
    if (contador == 1) {
      numero_estados = stoi(line);
    }
    if (contador == 2) {
      for (long unsigned int i = 0; i < line.size(); ++i) {
        if ((line[i] == ' ')&&(i < line.size())) {
          std::cout << "ERROR en la linea: " << line << std::endl;
          std::cout << "Solo puede haber un estado inicial" << std::endl;
          exit(1);
        }
      }
    }
    if (contador > 2){
      std::string aux;
      int i = 0;
      while(line[i] != ' ') {
        aux.push_back(line[i]);
        ++i;
      }
      retorno.insert(aux);
    }
    ++contador;
  }
  if (retorno.size() != numero_estados) {
    std::cout << "ERROR. Por cada estado debe haber una linea de declaracion " << std::endl;
    exit(1);
  }
  input_file.close();
  return retorno;
}

void Automata::Probar_Recursivo(std::string automata_entrada) {
  std::string line;
  std::ifstream input_file(automata_entrada);
  while (getline(input_file, line)) {
    Cadena actual (line, alfabeto_);
    std::set<std::string> estados_actuales;
    estados_actuales.insert(inicial_);
    ///Hay que tener en cuenta la posibilidad de que sean necesarios & al principio
    std::vector<std::string> auxiliar_estados;
    auxiliar_estados = Siguiente_Estado(estados_actuales, Simbolo("&"));
    for (auto estados : auxiliar_estados) {
      estados_actuales.insert(estados);
    }
    int iterador = 0;
    bool aceptacion = Estados_Recursivo(estados_actuales, actual, iterador);
    std::cout << line << " ----- " << (aceptacion ? "Accepted" : "Rejected") << std::endl;
  }
}

bool Automata::Estados_Recursivo(std::set<std::string> actuales, Cadena aux, int iterador) {
  if (iterador == aux.Tamano_Cadena()) {
    bool estado_final = false;
    for (auto estados_finales : actuales) {
      for (auto estados_aceptacion : finales_) {
        if (estados_aceptacion == estados_finales) {
          estado_final = true;
        }
      }
    }
    return estado_final;
  } else {
    std::vector<std::string> auxiliar_estados;
    auxiliar_estados = Siguiente_Estado(actuales, aux.palabra()[iterador]);
    actuales.clear();
    for (auto estado : auxiliar_estados) {
      actuales.insert(estado);
    }
    auxiliar_estados = Siguiente_Estado(actuales, Simbolo("&"));
      for (auto estados : auxiliar_estados) {
        actuales.insert(estados);
      }
    auxiliar_estados.clear();
    return (Estados_Recursivo(actuales, aux, ++iterador));
  }
}
