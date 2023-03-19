#pragma once

#include <iostream>

template <class Key>
class ExplorationFunction {
 public:
  unsigned operator() (const Key&, unsigned) const = 0;
};
