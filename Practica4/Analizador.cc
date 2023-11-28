// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Paula María Darias Sosa
// Correo: alu0101398594@ull.es
// Fecha: 23/10/2022
// Archivo Analizador.cc: desarollo de la clase Analizador
// Referencias:
// Historial de revisiones
// 23/10/2022 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <string>
#include "Analizador.h"
#include "Coincidentes.h"

Analizador::Analizador(std::string filename) {
  titulo_ = filename;
  std::ifstream input_file(titulo_);
  //Comentarios multilineas
  std::string line;
  int line_number = 1;
  int starting_line_number;
  int ending_line_number;
  std::string lines_acumulated;
  std::regex comment_start("\\/\\*");
  std::regex comment_end("\\*\\/");
  std::regex variable("^[ ]*((int)|(double)) [^=]+( =[^;]+)?;"); //espacios al principio, tipo de variable, algo antes del =, (si hay igual algo que no sea ;) 0 o 1 vez , ; final
  std::regex for_loop("for[ ]*\\([^)]+\\)");
  std::regex while_loop("while[ ]*\\([^)]+\\)");
  std::regex single_line_comment("//.*");
  std::regex main_aparicion("^[ ]*int main.\\([^\\)]*\\)?.\\{?");

  bool multilinea = false;
  while (getline(input_file, line)) {
    if (std::regex_search(line, comment_start)) {
      multilinea = true;
      starting_line_number = line_number;
      if (line_number == 1) {
        descripcion_ = true;
      }
    }
    if (multilinea == true) {
      lines_acumulated += (line + "\n");
      if (std::regex_search(line, comment_end)) {
        multilinea = false;
        ending_line_number = line_number;
        Caso_Comentario_Multilinea(lines_acumulated, starting_line_number, ending_line_number);
        lines_acumulated.clear();
      }
    } else {
      if (std::regex_search(line, single_line_comment)){
        Caso_Comentario(line, line_number);
        std::regex aux_comentario ("//.*");
        line = std::regex_replace(line, aux_comentario, "");
      }
      if (std::regex_search(line, while_loop)) {
        Caso_Bucle(line, line_number);
      }
      if (std::regex_search(line, for_loop)) {
         Caso_Bucle(line, line_number);
      } 
      if (std::regex_search(line, main_aparicion)) {
        main_ = true;
      } 
      if (std::regex_search(line, variable)) {
        Caso_Variable(line, line_number);
      }
    }
    ++line_number;
  }
}

void Analizador::Caso_Variable (std::string linea_actual, int numero_linea) {
  std::regex espacio ("^[ ]*");
  linea_actual = std::regex_replace(linea_actual,espacio, "");
  std::regex entero ("int");
  std::regex doble ("double");
  std::regex punto_coma (";");
  linea_actual = std::regex_replace(linea_actual, punto_coma, "");
  if (std::regex_search(linea_actual, entero) == 1) {
    linea_actual = std::regex_replace(linea_actual, entero, "INT:");
  } else {
    linea_actual = std::regex_replace(linea_actual, doble, "DOUBLE:");
  }
  variables_.push_back(Coincidecias(numero_linea, numero_linea, Type(1), linea_actual));
}

void Analizador::Caso_Bucle (std::string linea_actual, int numero_linea) {
  std::regex espacios ("^[ ]*");
  linea_actual = std::regex_replace(linea_actual,espacios, "");
  std::regex relleno ("(\\([^)]+\\)[ ]*[{]*)");
  linea_actual = std::regex_replace(linea_actual,relleno, "");
  bucles_.push_back(Coincidecias(numero_linea, numero_linea, Type(2), linea_actual));
}

void Analizador::Caso_Comentario (std::string linea_actual, int numero_linea) {
  std::regex aux_eliminar_exceso (".*//");
  linea_actual = std::regex_replace(linea_actual,aux_eliminar_exceso, "//");
  comentarios_.push_back(Coincidecias(numero_linea, numero_linea, Type(3), linea_actual));
}

void Analizador::Caso_Comentario_Multilinea (std::string linea_acumulada, int numero_linea_inicio, int numero_linea_final) {
  comentarios_multilinea_.push_back (Coincidecias(numero_linea_inicio, numero_linea_final, Type(4), linea_acumulada));
}

void Analizador::Read (std::string kFileName2) {
  std::ofstream output_file;
  output_file.open(kFileName2, std::ofstream::out);
  output_file << "TITULO: " << titulo_ << "\n";
  output_file <<  "\n";
  if (descripcion_ == true) {
    output_file << "DESCRIPCION: " << "\n";
    output_file << comentarios_multilinea()[0].info() << "\n";
    output_file <<  "\n";
  }
  output_file << "VARIABLES: " << "\n";
  for (auto aux : variables()) {
    output_file << aux << "\n";
  }
  output_file <<  "\n";
  output_file << "DECLARACIONES: " << "\n";
  for (auto aux : bucles()) {
    output_file << aux << "\n";
  }
  output_file <<  "\n";
  output_file << "COMENTARIOS: " << "\n";
  for (auto aux : comentarios()) {
    output_file << aux << "\n";
  }
  for (long unsigned int i = 0; i < comentarios_multilinea().size(); ++i) {
    if ((descripcion() == true) && (i == 0)) {
      output_file << "[Line " << comentarios_multilinea()[i].inicio() << " - " << comentarios_multilinea()[i].final() << "] " << "DESCRIPCION" << "\n";
    } else {
      output_file << comentarios_multilinea()[i] << "\n";
    }
  }
  output_file <<  "\n";
  output_file << "MAIN: ";
  if (main_ == true) {
    output_file << "True" << "\n";
  } else {
    output_file << "False" << "\n";
  }
  output_file.close();
}