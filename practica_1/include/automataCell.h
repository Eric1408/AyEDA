#pragma once

#include <iostream>

class Lattice;

using Position = int;
using State = int;

class Cell {
 private:
  Position position_;
  State state_;
 public:
  Cell(const Position& pos, const State& initialState = 0) : position_(pos), state_(initialState) {}
  Cell() : position_{}, state_{} {}

  void updateState(const Cell);
  State nextState(const Lattice&);
  State getState() const { return state_; }
  void setState(const State& newState) { state_ = newState; } 
  
  // Aditional method that returns position_
  Position getPosition() { return position_; }
  
  // Sobrecarga del operador de inserción en flujo para la visualización en pantalla
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << (cell.getState() == 1 ? 'X' : '_');
    return os;
  }
};