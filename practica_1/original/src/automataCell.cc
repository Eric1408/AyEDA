#include "automataCell.h"
#include "lattice.h"

State CalculateNextState(const State state[3]) {
  State left = state[0];
  State center = state[1];
  State right = state[2];
  State next;

  if(left == 1 && center == 1 && right == 1) {
    next = 0;
  } else if(left == 1 && center == 1 && right == 0) {
    next = 1;
  } else if(left == 1 && center == 0 && right == 1) {
    next = 1; 
  } else if(left == 1 && center == 0 && right == 0) {
    next = 0;
  } else if(left == 0 && center == 1 && right == 1) {
    next = 1;
  } else if(left == 0 && center == 1 && right == 0) {
    next = 1;
  } else if (left == 0 && center == 0 && right == 1) {
    next = 1;
  } else if(left == 0 && center == 0 && right == 0) {
    next = 0;
  }

  return next;
}

State Cell::nextState(const Lattice& lattice) {
  int latticeSize = lattice.getSize();
  State states[3];
  Position left;
  Position right;

  State rightNeighborState;
  State leftNeighborState;

  if (lattice.getIsPeriodic()) {
    if (position_ == 0) {
      left = latticeSize -1;
      right = position_ +1;
    } else if (position_ == latticeSize -1) {
      left = position_ -1;
      right = 0;
    } else {
      left = position_ -1;
      right = position_ +1;
    }

    leftNeighborState = lattice.getCell(left).getState();
    rightNeighborState = lattice.getCell(right).getState();

  } else {
    right = position_ +1;
    left = position_ -1;
    if (position_ == 0) {
      leftNeighborState = lattice.getAuxState();
      rightNeighborState = lattice.getCell(right).getState();
    } else if (position_ == latticeSize -1) {
      rightNeighborState = lattice.getAuxState();
      leftNeighborState = lattice.getCell(left).getState();
    } else {
      leftNeighborState = lattice.getCell(left).getState();
      rightNeighborState = lattice.getCell(right).getState();
    }
  }

  State currentState = getState();
  
  states[0] = leftNeighborState;
  states[1] = currentState;
  states[2] = rightNeighborState;

  return CalculateNextState(states);
}

void Cell::updateState(const Cell newCell) {
  state_ = newCell.getState();
}
