#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "lattice.h"

int main(int argc, char* argv[]) {
  int size = std::stoi(argv[1]);
  std::string border = argv[2];
  std::string file = argv[4];
  int isWarm = (argc == 4) ? std::stoi(argv[3]) : 0; 

  Lattice lattice(size);

  lattice.loadInitialConfiguration(border, isWarm);
  //lattice.setFileConfiguration(file);
  std::cout << lattice << std::endl;
  while (true) {
    lattice.nextGeneration();
    std::cout << lattice << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  return 0;
}