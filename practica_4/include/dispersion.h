#pragma once 

#include <string>
#include <iostream>
#include <random>

template <class Key>
class DispersionFunction {
 public:
  unsigned operator() (const Key& k) const = 0;

};
