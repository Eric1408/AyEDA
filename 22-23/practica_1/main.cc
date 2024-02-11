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
#include <stack>
#include <map>

#include "usage.h"
#include "bigInt.h"
#include "board.h"

int main(int argc, char* argv[]) {
  //Usage(argc, argv[]);
  std::ifstream input{std::string(argv[1])};
  std::string lines;
  
  // OBTENER LA BASE
  getline(input, lines);
  size_t pos = lines.find("=");
  std::string lines_substr = lines.substr(pos + 2);
  size_t base = stoi(lines_substr);
  
  std::string no = "192203BDC5838";
  BigInt<10> op(no);
  
  
  // OBTENER LAS EXPRESIONES
  while (std::getline(input, lines)) {
    pos = lines.find("=");
    std::string value = lines.substr(pos + 2);
    std::string key = lines.substr(0, pos - 1);
    BigInt<10> sample(value);
    std::cout << sample << " + " << op  << " : " << sample + op << std::endl;
    
  }

  return 0;
}

