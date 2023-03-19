#pragma once 

#include <iostream>

template <class Key>
class Sequence {
 public:
  unsigned operator() (const Key& k) const = 0;
  bool search(const Key&) const = 0;
 protected:
};