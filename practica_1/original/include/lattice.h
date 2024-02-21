#pragma once 

#include <iostream>
#include <vector>
#include <fstream>

#include "automataCell.h"

class Lattice {
 private:
  Cell* cells_;
  int size_;

  // Auxiliar variables
  State aux_;
  bool isPeriodic_;
 public:
  Lattice(int);
  ~Lattice();

  void nextGeneration();
  void loadInitialConfiguration(const std::string&, int);
  const Cell& getCell(const Position&) const;

  // Additional code for a correct implementation
  int getSize() const { return size_; }
  State getAuxState() const { return aux_; }
  bool getIsPeriodic() const { return isPeriodic_; }  
  void setFileConfiguration(const std::string&);

  friend std::ostream& operator<<(std::ostream&, const Lattice&);
};