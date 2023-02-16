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

int main(int argc, char* argv[]) {
  //Usage(argc, argv[]);
  std::ifstream input{std::string(argv[1])};
  std::string lines;
  
  // OBTENER LA BASE
  getline(input, lines);
  size_t pos = lines.find("=");
  std::string lines_substr = lines.substr(pos + 2);
  int base = stoi(lines_substr);
  
  
  std::stack<std::string> expresiones;

  while (std::getline(input, lines)) {
    pos = lines.find("=");
    if (std::string::npos != pos) {
      
    }
    std::string value = lines.substr(pos + 2);
    std::string key = lines.substr(0, pos - 1);
    std::cout << "a\n"; 
    BigInt<10> sample(value);
    std::cout << sample << std::endl;
    std::cout << "b\n";
    std::cout << sample + sample << std::endl;
    
    std::cout << "value : " << value << " and key : " << key << std::endl;
  }

  std::string algo ="442142117615672";
  BigInt<10> op1(algo);
  std::string algo_2 = "46651367647546";
  BigInt<10> op2(algo_2);

  std::cout << op1  << std::endl;

  return 0;
}

