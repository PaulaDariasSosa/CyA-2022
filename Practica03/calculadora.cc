// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo calculadora.cc: el desarollo de las funciones declaracas en calculadora.h
// necesarias para realizar las operaciones necesarias para la Practica 3 
// Referencias:
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento

#include "calculadora.h"

bool Operandos_en_pila (std::stack<Lenguaje> operaciones, int necesarios) {
  if (operaciones.size() < necesarios) {
    std::cout << "ERROR: Operandos insuficientes en la expresíon." << std::endl;
    return false;
  }
  return true;
}

bool Posible_Lenguaje (std::string line) {
  bool todo_correcto = true;
  int contador = 0;
  while (line[contador] != ' ') {
    ++contador;
  }
  if ((line[contador] != ' ')&&(line[contador + 2] != ' ')) {
    std::cout << "Debe hacerse un uso correcto de los espacios. Para mas informacion pruebe '--help'" << std::endl;
    return false;
  }
  if (line[++contador] != '=') {
    std::cout << "Para realizar la asignacion de lenguajes debera hacerse uso del signo '='. Para mas informacion pruebe '--help'" << std::endl;
    return false;
  }
  ++contador; // ya ha sido comprobado anteriormente
  if (line[++contador] == '{') {
    ++contador;
    while ((contador < line.size() - 1) && (line[contador] != '}')) {
      if (line[contador] == '{') { // fallo por si encuentra una abertura de llave
        std::cout << "El lenguaje no puede contener llaves" << std::endl;
        return false;
      }
      if (line[contador] == ',') {
        if (line[contador + 1] != ' ') { // fallo por si despues de una coma no va un espacio
          std::cout << "Las comas deben estar seguidas de un espacio" << std::endl;
          return false; // crear funcion para la comprobacion de estas cosas para poder hacer break en la funcion pricipal
        }
      }
      if ((line[contador] != ' ') && (line[contador] != ',')) { // nos evitamos meter en el alfabeto o la cadena comas o espacios
        if ((line[contador] == '&') && !(((line[contador - 1] == ' ') && (line[contador + 1] == ',')) || ((line[contador - 1] == '{') && (line[contador + 1] == '}')) || ((line[contador - 1] == '{') && (line[contador + 1] == ',')) || ((line[contador - 1] == ' ') && (line[contador + 1] == '}')))) { 
          std::cout << "La cadena vacia no puede estar unida otra cadena" << std::endl; 
          return false;
        }
      }
      ++contador;
      if (contador == line.size() - 1) {
        if (line[contador] != '}') {
          std::cout << "La definicion del lenguaje debe terminar con cierre de llaves" << std::endl;
          return false;
        }
      }
    }
    if (contador != line.size() - 1) {
      std::cout << "El lenguaje no puede contener llaves" << std::endl;
      return false;
    }
  } else {
    std::cout << "Para realizar la declaracion de lenguajes debera hacerse uso de las llaves '{}'. Para mas informacion pruebe '--help'" << std::endl;
    return false;
  }
  return todo_correcto;
}

void Calculadora_lenguajes (std::string kFileName) {
  std::ifstream input_file1(kFileName, std::ios_base::in);
  std::string line;
  std::map<std::string, Lenguaje> intento_almacen;
  std::string aux;
  while(getline(input_file1, line)) {
    std::stack<Lenguaje> operaciones; 
    std::stack<int> potencias; 
    bool imposible_operacion = true;
    for (int i = 0; i < line.size(); ++i) {
      char caracter_actual = line[i];
      switch (caracter_actual) {
        case ('=') : {
          if (Posible_Lenguaje(line)) {
            Lenguaje aux_lenguaje = line; // debe ser una pila donde metamos los lenguajes, sin mas
            intento_almacen.insert_or_assign(aux, aux_lenguaje); // saco el lenguaje de la pila ya que no era una operacion, sino una declaracion
          }
          aux.clear();
          i = line.size(); // para saltarnos el resto de la linea
        }
        break;
        case ('+') : {
          if (Operandos_en_pila(operaciones, 2)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            Lenguaje a_operar2 = operaciones.top();
            operaciones.pop();
            operaciones.push(a_operar2 + a_operar1);
          } else {
            i = line.size(); 
            imposible_operacion = false;
          }
        }
        break;
        case ('|') : {
          if (Operandos_en_pila(operaciones, 2)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            Lenguaje a_operar2 = operaciones.top();
            operaciones.pop();
            operaciones.push(a_operar2 | a_operar1);
          }
           else {
            i = line.size(); 
            imposible_operacion = false;
          }
        }
        break;
        case ('^') : {
          if (Operandos_en_pila(operaciones, 2)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            Lenguaje a_operar2 = operaciones.top();
            operaciones.pop();
            operaciones.push(a_operar2 ^ a_operar1);
          }
           else {
            i = line.size(); 
            imposible_operacion = false;
          }
        }
        break;
        case ('-') : {
          if (Operandos_en_pila(operaciones, 2)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            Lenguaje a_operar2 = operaciones.top();
            operaciones.pop();
            operaciones.push(a_operar2 - a_operar1);
          }
           else {
            i = line.size(); 
            imposible_operacion = false;
          }
        } 
        break;
        case ('!') : {
          if (Operandos_en_pila(operaciones, 1)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            operaciones.push(!a_operar1);
          } else {
            i = line.size(); 
            imposible_operacion = false;
          }         
        }
        break;
        case ('*') : {
          if (Operandos_en_pila(operaciones, 1)) {
            Lenguaje a_operar1 = operaciones.top();
            operaciones.pop();
            int potencia = potencias.top();
            potencias.pop();
            operaciones.push(a_operar1 * potencia);
          }  else {
            i = line.size(); 
            imposible_operacion = false;
          }
        }
        break;
        default :
          if (isdigit(line[i])) {
            potencias.push(line[i] - '0');
            break;
          }
          while ((line[i] != ' ') && (i < line.size())) {
            aux.push_back(line[i]);
            ++i;
          }
          if (intento_almacen.count(aux)) { // si el elemento ya tiene una declaracion 
            auto buscar = intento_almacen.find(aux);
            operaciones.push(buscar->second);
          }
          if (line[i + 1] != '=') {
            aux.clear();
          }
          
      }
    }
    if (operaciones.size() == 1) {
      if (imposible_operacion == true) {
        std::cout << operaciones.top() << std::endl;
      }
    } else {
      if (operaciones.size() != 0) {
        std::cout << "ERROR: Expresión incorrecta." << std::endl;
      }
    }
  }
}