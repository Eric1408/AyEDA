#ifndef CELL_H
#define CELL_H

#include <utility>

typedef std::pair<unsigned, unsigned> Position;
typedef int State;

class Cell {
 protected:
  State state_;
  Position pos_;
 public:
  
};

#endif
