/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Algoritmos y Estructura de Datos Avanzados
 * @file main.cc
 * @brief  
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2023-0-
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>

#include "usage.h"

int main(int argc, char* argv[]) {
  //Usage(argc, argv[]);
  std::ifstream input = argv[0];
  std::string lines;
  
  input >> lines;
  int pos = lines.find("=");
  std::string str_value = lines.substr(pos + 2);
  int base = stoi(str_value);

  while (std::getline(input, lines)) {
    
  }

  return 0;
}

