#include <iostream>
#include <string>

#include "lattice.h"

Lattice::Lattice(int size) : size_{size} {
  cells_ = new Cell[size];
  for (int i = 0; i < size; ++i) {
    cells_[i] = Cell(i);
  }
}

Lattice::~Lattice() {
  delete[] cells_;
}

void Lattice::loadInitialConfiguration(const std::string& option, int isWarm) {
  if (option == "periodic") {
    isPeriodic_ = true;
  } else {
    isPeriodic_ = false;
    aux_ = isWarm;
  }

  for (int i = 0; i < size_; ++i) {
    cells_[i].setState(0);
  }

  int middle = size_ / 2;
  cells_[middle].setState(1);
}

const Cell& Lattice::getCell(const Position& pos) const {
  return cells_[pos];
} 

void Lattice::nextGeneration() {
  Cell* newStates = new Cell[size_];
  
  // Calculate next states for each cell
  for (int i = 0; i < size_; ++i) {
    newStates[i] = Cell(i);
    State nextState = cells_[i].nextState(*this);
    newStates[i].setState(nextState);
  }

  // Update states based on the calculated next states
  for (int i = 0; i < size_; ++i) {
    cells_[i].updateState(newStates[i]);
  }

  delete[] newStates;
}


std::ostream& operator<<(std::ostream& os, const Lattice& latt) {
  for(int i = 0; i < latt.size_; ++i) {
    os << latt.cells_[i];
  }

  return os;
}

void Lattice::setFileConfiguration(const std::string& nameFile) {
  std::ifstream confile(nameFile);
  if (confile.is_open()) {
    for (int i = 0; i < size_; ++i) {
      State state;

      // Try to read the state from the file
      if (!(confile >> state)) {
        std::cerr << "Error reading state from file." << std::endl;
      }

      cells_[i].setState(state);
    }

    // Check if there are extra characters in the file
    char extraChar;
    if (confile >> extraChar) {
      std::cerr << "Warning: Extra characters found in the file." << std::endl;
      // Handle the warning as needed
    }

    // Close the file
    confile.close();
  } else {
    std::cerr << "Unable to open file: " << nameFile << std::endl;
  }

}
