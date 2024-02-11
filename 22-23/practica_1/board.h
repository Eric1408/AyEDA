#pragma once

#include <iostream>
#include <string>
#include <map>

#include "bigInt.h"

template<size_t Base = 10>
class RPN {
 public:
  using bigIntMap = std::map<std::string, BigInt<Base>>;

 private:
  bigIntMap map_;
};

// result = map<string, evaluate(string)> evaluatez -> devuelve un bigint