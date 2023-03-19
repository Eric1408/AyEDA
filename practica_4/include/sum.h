#pragma once 

#include "dispersion.h"

template <class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n) : table_size{n} {}
  unsigned operator()(const Key&) const;
 private:
  unsigned table_size_;
};

template <class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
  unsigned sum = 0;
  Key tmp = k;
  
  while (tmp > 0) {
    sum += tmp % 10;
    tmp /= 10;
  }

  return sum % table_size_;
}
