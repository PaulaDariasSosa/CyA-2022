// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 16/10/2022
// Archivo lenguaje.cc: programa que contiene el desarollo de la clase Lenguaje.
// Contiene el desarollo de la clase Lenguaje
// Historial de revisiones
// 15/10/2022 - Creación (primera versión) del código
// 16/10/2022 - Correcion de constructor Lenguaje
// 17/10/2022 - Correcion de error generales
// 18/10/2022 - Correcion error entero potencia en documento


#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"
const std::string str_aux = {"&"};
const Simbolo simbolo_VACIO = str_aux;
const std::vector<Simbolo> cadena_vacio = {simbolo_VACIO};
const Cadena VACIO = cadena_vacio;

Lenguaje::Lenguaje (std::string line) {
  std::set<std::string> alfabeto;
  int contador = 0;
  while (line[contador] != ' ') {
    ++contador;
  }
  contador += 4; // ya ha sido comprobado anteriormente
  std::vector<Simbolo> cadena_auxiliar;
  while ((contador < line.size() - 1) && (line[contador] != '}')) {
    if (line[contador] == ',') {
        lenguaje_.insert(cadena_auxiliar); //despues de la coma insertamos en el lenguaje la cadena acumulada
        cadena_auxiliar.clear(); // limpiamos la cadena para empezar de cero
      }
      if ((line[contador] != ' ') && (line[contador] != ',')) { // nos evitamos meter en el alfabeto o la cadena comas o espacios
        std::string simbolo_aux;
        simbolo_aux.push_back(line[contador]);
        if (line[contador] != '&') {
          alfabeto.insert(simbolo_aux);// siempre y cuando el simbolo actual no sea &, lo insertamos en el alfabeto
        }
        cadena_auxiliar.push_back(Simbolo(simbolo_aux));
      }
      ++contador;
      if (contador == line.size() - 1) {
        if (line[contador] == '}') {
          lenguaje_.insert(cadena_auxiliar);
        }
      }
    }
  raiz_ = alfabeto;
}
// Constructor copia de Lenguaje 
Lenguaje::Lenguaje (const Lenguaje& otro) {
  lenguaje_.clear();
  raiz_ = otro.raiz();
  for (auto cadena_aux : otro.lenguaje()) {
    lenguaje_.insert(cadena_aux);
  }
}

std::ostream& operator<<(std::ostream& out, const Lenguaje& actual) {
  out << "{ ";
  for (auto cadena: actual.lenguaje()) {
  out << cadena << " ";
  }
  out << "}";
  return out;
}

Lenguaje Lenguaje::Concatenacion(const Lenguaje& lenguaje2) {
  std::set<Cadena> concatenado;
  for (auto cadena_actual1 : lenguaje()) {
    if (!(cadena_actual1 == VACIO)) {
      for (auto cadena_actual2 : lenguaje2.lenguaje()) {
        if (!(cadena_actual2 == VACIO)) {
          Cadena auxiliar = cadena_actual1 + cadena_actual2;
          concatenado.insert(auxiliar);
        } else {
          Cadena auxiliar = cadena_actual1;
          concatenado.insert(auxiliar);
        }
      }
    } else {
      for (auto cadena_actual2 : lenguaje2.lenguaje()) {
      Cadena auxiliar = cadena_actual2;
      concatenado.insert(auxiliar);
      }
    }
  }
  Lenguaje lenguaje_concatenado = concatenado;
  lenguaje_concatenado.raiz_ = raiz() + lenguaje2.raiz();
  return lenguaje_concatenado;
}

Lenguaje Lenguaje::Union(const Lenguaje& lenguaje2) {
  std::set<Cadena> concatenado;
  for (auto cadena_actual1 : lenguaje()) {
    concatenado.insert(cadena_actual1);
  }
  for (auto cadena_actual2 : lenguaje2.lenguaje()) {
    concatenado.insert(cadena_actual2);
  }
  Lenguaje lenguaje_concatenado = concatenado;
  lenguaje_concatenado.raiz_ = raiz() + lenguaje2.raiz();
  return lenguaje_concatenado;
}

Lenguaje Lenguaje::Diferencia(const Lenguaje& lenguaje2) {
  std::set<Cadena> concatenado;
  for (auto cadena_actual1 : lenguaje()) {
    bool cadena_encontrada = false;
    for (auto cadena_actual2 : lenguaje2.lenguaje()) {
      if (cadena_actual1 == cadena_actual2) {
        cadena_encontrada = true;
      }
    }
    if (cadena_encontrada == false) {
      concatenado.insert(cadena_actual1);
    }
  }
  Lenguaje lenguaje_concatenado = concatenado;
  lenguaje_concatenado.raiz_ = raiz();
  return lenguaje_concatenado;
}

Lenguaje Lenguaje::Interseccion(const Lenguaje& lenguaje2) {
  std::set<Cadena> concatenado;
  for (auto cadena_actual1 : lenguaje()) {
    for (auto cadena_actual2 : lenguaje2.lenguaje()) {
      if (cadena_actual1 == cadena_actual2) {
        concatenado.insert(cadena_actual1);
      } 
    }
  }
  Lenguaje lenguaje_concatenado = concatenado;
  lenguaje_concatenado.raiz_ = raiz().Interseccion(lenguaje2.raiz());
  return lenguaje_concatenado;
}

Lenguaje Lenguaje::Inversa() {
  std::set<Cadena> concatenado;
  for (auto cadena_actual1 : lenguaje()) {
    concatenado.insert(cadena_actual1.Inversa_Cadena());
  }
  Lenguaje lenguaje_concatenado = concatenado;
  lenguaje_concatenado.raiz_ = raiz();
  return lenguaje_concatenado;
}

Lenguaje Lenguaje::Potencia(int iteraciones) {
  std::set<Cadena> elevado;
  Lenguaje lenguaje_inicial = *this;
  Lenguaje lenguaje_elevado = *this;
  if (iteraciones == 0) {
    std::vector<Simbolo> cadena_aux;
    cadena_aux.push_back(Simbolo("&"));
    elevado.insert(Cadena(cadena_aux));
    Lenguaje lenguaje_elevado = elevado;
    lenguaje_elevado.raiz_ = raiz();
    return lenguaje_elevado;
  }
  if (iteraciones == 1) {
    for (auto cadena_aux: lenguaje()) {
      elevado.insert(cadena_aux);
    }
    Lenguaje lenguaje_elevado = elevado;
    lenguaje_elevado.raiz_ = raiz();
    return lenguaje_elevado;
  }
  --iteraciones; // Porque el caso potencia = 1, ya esta contenplado
  while (iteraciones != 0) {
    Lenguaje aux = lenguaje_elevado.Concatenacion(lenguaje_inicial);
    lenguaje_elevado = aux;
    --iteraciones;
  }
  lenguaje_elevado.raiz_ = raiz();
  return lenguaje_elevado;
}

Lenguaje operator+(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Concatenacion(lenguaje2);
}

Lenguaje operator|(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Union(lenguaje2);
}

Lenguaje operator^(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Interseccion(lenguaje2);
}

Lenguaje operator-(const Lenguaje& lenguaje1, const Lenguaje& lenguaje2) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Diferencia(lenguaje2);
}

Lenguaje operator!(const Lenguaje& lenguaje1) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Inversa();
}

Lenguaje operator*(const Lenguaje& lenguaje1, int iteraciones) {
  Lenguaje lenguaje_aux = lenguaje1;
  return lenguaje_aux.Potencia(iteraciones);
}