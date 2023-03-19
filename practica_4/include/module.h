#pragma once 

#include <iostream>
#include <string>

#include "dispersion.h"

template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n) : table_size{n} {}
  unsigned operator()(const Key&) const;
 private:
  unsigned table_size_;
};

template <class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % table_size_;
}
