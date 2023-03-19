#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "sequence.h"

template <class Key>
class HashTable {
 public:
  HashTable(int size);
 private:
  int size_;
  // is this okay?
  std::vector<Sequence<Key>*> table_;
};