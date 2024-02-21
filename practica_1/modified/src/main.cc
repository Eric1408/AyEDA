// https://www.cs.us.es/~fsancho/Blog/posts/Automatas_Celulares.md.html
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "../include/lattice.h"


void printUsage() {
  std::cout << "Uso: nombre_del_programa <size> <border> [isWarm] <file>\n";
  std::cout << "   <size>: Tamaño del lattice (entero positivo)\n";
  std::cout << "   <border>: [open [1 | 0] | periodic]\n";
}

int main(int argc, char* argv[]) {
  if (argc != 3 && argc != 4) {
    std::cerr << "Número incorrecto de argumentos.\n";
    printUsage();

    return 1; 
  }

  int size = std::stoi(argv[1]);
  std::string border = argv[2];
  int isWarm = (argc == 4) ? std::stoi(argv[3]) : 0;
  
  Lattice lattice(size);

  lattice.loadInitialConfiguration(border, isWarm);
  std::cout << lattice << std::endl;
  while (true) {
    lattice.nextGeneration();
    std::cout << lattice << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  return 0;
}