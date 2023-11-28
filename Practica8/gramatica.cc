/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica #08: Gramáticas en Forma Normal de Chomsky
/// Autor: Paula María Darias Sosa
/// Correo: alu0101398594@ull.es
/// Fecha: 21/11/2022
/// Archivo gramatica.cc: desarollo de la clase Gramatica
/// Referencias:
/// Historial de revisiones
/// 21/11/2022 - Creación (primera versión) del código
#include "producciones.h"
#include "gramatica.h"
#include <fstream>

/**
 * @brief Constructor de la clase Gramatica a partir de un documento
*/

Gramatica::Gramatica(std::string filename) {
  std::ifstream input_file(filename);
  std::string line;
  std::set<std::string> simbolo_terminales;
  getline(input_file, line);
  int n_terminales = stoi(line);
  while (n_terminales != 0) {
    getline(input_file, line);
    simbolo_terminales.insert(line);
    --n_terminales;
  }
  std::set<std::string> simbolo_no_terminales;
  getline(input_file, line);
  int n_no_terminales = stoi(line); 
  while (n_no_terminales != 0) {
    getline(input_file, line);
    simbolo_no_terminales.insert(line);
    --n_no_terminales;
  }
  getline(input_file, line);
  Simbolo_Arranque_ = line;
  getline(input_file, line);
  while (getline(input_file, line)) {
    std::vector <Produccion> producciones;
    std::string nombre_produccion;
    long unsigned int i = 0;
    while (line[i] != ' '){
      nombre_produccion.push_back(line[i]);
      ++i;
    }
    ++i;
    while (line[i] != ' '){
      ++i;
    }
    ++i;
    std::string auxiliar;
    std::vector<std::string> produccion_temporal;
    while (i <= line.size()) {
      while ((line[i] != ' ')&&(i <= line.size())) {
        auxiliar.push_back(line[i]);
        if (Alfabeto(simbolo_terminales).Buscar_Simbolo(Simbolo(auxiliar))) {
          produccion_temporal.push_back(auxiliar);
          auxiliar.clear();
        } else {
          if (Produccion_Existe(simbolo_no_terminales, auxiliar)) {
            produccion_temporal.push_back(auxiliar);
            auxiliar.clear();
          } else {
            if (auxiliar == "&") {
              produccion_temporal.push_back(auxiliar);
              auxiliar.clear();
            }
          }
        }
        ++i;
      }
      ++i;
      if(line[i] == '|') ++i;
      ++i;//saltamos espacio
      producciones.push_back(Produccion(produccion_temporal));
      produccion_temporal.clear();
    }
    producciones_.insert_or_assign(nombre_produccion, producciones);
    Simbolos_Terminales_ = Alfabeto(simbolo_terminales);
    Simbolos_No_Terminales_ = simbolo_no_terminales;
  }
}

/**
 * @brief Comprueba si una Produccion existe
 * @return true o false
*/

bool Gramatica::Produccion_Existe(std::set<std::string> estados_posibles, std::string estado_a_probar) {
  bool existencia = false;
  for (auto estado_actual : estados_posibles) {
    if (estado_actual == estado_a_probar) {
      existencia = true;
    }
  }
  return existencia;
}

/**
 * @brief Imprime la gramatica en el documento dado
*/

void Gramatica::Imprimir(std::string kFileName) {
  std::ofstream output_file;
  output_file.open(kFileName, std::ofstream::out);
  output_file << Simbolos_Terminales_.alfabeto().size() << std::endl;
  for (auto simbolo : Simbolos_Terminales_.alfabeto()) {
    output_file << simbolo.caracter() << std::endl;
  }
  output_file << Simbolos_No_Terminales_.size() << std::endl;
  for (auto simbolo : Simbolos_No_Terminales_) {
    output_file << simbolo << std::endl;
  }
  output_file << Simbolo_Arranque_ << std::endl;
  int contador_prduccion = 0;
  for (auto estado : producciones_) {
    for (auto simbolo_estado : estado.second) {
      ++contador_prduccion;
    }
  }
  output_file << contador_prduccion << std::endl;
  for (auto estado : producciones_) {
    output_file << estado.first << " -> ";
    long unsigned int numero_prod = estado.second.size();
    long unsigned int contador = 0;
    for (auto producciones : estado.second) {
      for (auto produccion : producciones.produccion()) {
        output_file << produccion;
      }
      ++contador;
      if (numero_prod != contador) {
        output_file << " | ";
      }
    }
    output_file << std::endl;
  }
}

/**
 * @brief Añade una produccion 
*/

void Gramatica::Add_Produccion(std::string Nombre, std::vector<Produccion> nueva_produccion) {
  producciones_.insert_or_assign(Nombre, nueva_produccion);
}

/**
 * @brief Convierte la gramatica dada en FNC
 */

void Gramatica::Pasar_FN() {
  bool En_FN = false;
  Produccion auxiliar;
  bool hay_simbolo = false;
  for (auto simbolo : Simbolos_Terminales_.alfabeto()) {
    std::string numero_simbolo = simbolo.caracter();
    std::string nombre_produccion = "C" + numero_simbolo;
    for (auto &producciones : producciones_) {
      for (auto &produccion : producciones.second ) {
        for (auto &cadena_actual : produccion.produccion_) {
          if ((cadena_actual == simbolo.caracter())&&(produccion.produccion().size() != 1)) {
            hay_simbolo = true;
            cadena_actual = nombre_produccion;
          }
          if ((cadena_actual == "&")&&(produccion.produccion().size() == 1)) {
            std::cout << "ERROR: no puede hacer producciones vacias para pasar a FNC" << std::endl;
            exit(1);
          }
          if ((Produccion_Existe(Simbolos_No_Terminales_, cadena_actual))&&(produccion.produccion().size() == 1)) {
            std::cout << "ERROR: no puede hacer producciones unitarias para pasar a FNC" << std::endl;
            exit(1);
          }
        }

      }
    }
    if (hay_simbolo == true) {
      std::vector<std::string> aux;
      aux.push_back(simbolo.caracter());
      std::vector<Produccion> a_insertar;
      a_insertar.push_back(Produccion(aux));
      producciones_.insert_or_assign(nombre_produccion, a_insertar);
      Simbolos_No_Terminales_.insert(nombre_produccion);
    }
  }
  std::vector<std::string> nueva_produccion;
  char numero = 'a';
  std::string nombre = "D";
  while (En_FN != true) {
    En_FN = true;
    for (auto &producciones : producciones_) {
      std::string nombre_produccion = nombre + numero;
      for (auto &produccion : producciones.second ) {
        int n_no_terminales = 0;
        for (auto &cadena_actual : produccion.produccion_) {
          if (Produccion_Existe(Simbolos_No_Terminales_, cadena_actual)) {
            ++n_no_terminales;
          }
        }
        if (n_no_terminales >= 3) {
          En_FN = false;
          int contador_produccion = 0;
          for (auto &cadena_actual : produccion.produccion_) {
            if (contador_produccion != 0) {
              nueva_produccion.push_back(cadena_actual);
              if (contador_produccion == 1) {
                cadena_actual = nombre_produccion;
                ++numero;
              } else {
                cadena_actual.clear();
              }
            } 
            ++contador_produccion;
          }
          std::vector<Produccion> aux; 
          aux.push_back(Produccion(nueva_produccion));
          if (Produccion_Igual(producciones_, Produccion(nueva_produccion))) {
            nombre_produccion = Nombre_Igual(producciones_, Produccion(nueva_produccion));
            int contador_produccion = 0;
            for (auto &cadena_actual : produccion.produccion_) {
              if (contador_produccion == 1) {
                cadena_actual = nombre_produccion;
              }
              ++contador_produccion;
            }
          }
          Add_Produccion(nombre_produccion, aux);
          nueva_produccion.clear();
          std::string nombre_produccion = nombre + numero;
        }
      }
    }
  }
}

/**
 * @brief Busca si existe una produccion igual
 * @return true o false
*/

bool Gramatica::Produccion_Igual(std::map<std::string, std::vector<Produccion>> producciones, Produccion p1) {
  bool retorno = false;
  for (auto producciones : producciones_) {
    for (auto produccion : producciones.second ) {
      if (produccion == p1) {
        retorno = true;
      }
    }
  }
  return retorno;
}

/**
 * @brief Busca el nombre de la produccion que es igual
 * @return el nombre de esta
*/

std::string Gramatica::Nombre_Igual(std::map<std::string, std::vector<Produccion>> producciones, Produccion p1) {
  std::string retorno;
  for (auto producciones : producciones_) {
    for (auto produccion : producciones.second ) {
      if (produccion == p1) {
        retorno = producciones.first;
      }
    }
  }
  return retorno;
}