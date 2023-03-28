#pragma once

#include <iostream>
#include <string>
#include <random>

#include "dispersion.h"
template <class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator() (const Key&, unsigned) const = 0;
};

/**
 * @brief Exploration function based on the lineal method
 * of the key
*/
template <class Key>
class feLineal : public ExplorationFunction<Key> {
 public:
  unsigned operator() (const Key&, unsigned i) const { return i; }
};

/**
 * @brief Exploration function ba sed on the double method
 * of the key
*/
template <class Key>
class feDouble : public ExplorationFunction<Key> {
 public:
  unsigned operator() (const Key&, unsigned) const;
};

template <class Key>
unsigned feDouble<Key>::operator() (const Key& k, unsigned i) const {
  return i*i;
}

/**
 * @brief Exploration function based on the double hash method
 * of the key
*/
template <class Key>
class feDoubleHash : public ExplorationFunction<Key> {
 private:
  DispersionFunction<Key>* disp_;
  //unsigned n_;
 public:
  //feDoubleHash (DispersionFunction<Key>* disp, unsigned size) : disp_{disp}, n_{size} {}
  feDoubleHash (DispersionFunction<Key>* disp) : disp_{disp} {}
  
  unsigned operator() (const Key&, unsigned) const;
};

template <class Key>
unsigned feDoubleHash<Key>::operator() (const Key& k, unsigned i) const {
  return i*(*disp_)(k);
}

/**
 * @brief Exploration function based on the rehash method
 * of the key
*/
template <class Key>
class feReHash : public ExplorationFunction<Key> {
 private:
  unsigned size_;
 public:
  feReHash (unsigned size) : size_{size} {}
  unsigned operator() (const Key&, unsigned) const;
};

template <class Key>
unsigned feReHash<Key>::operator() (const Key& k, unsigned i) const {
  fdPseudo<Key> disp(size_);
  disp(k);

  for (int j = 0; j < i-1 ; j++) {
    if (j == i) return rand();
    rand();
  }
}
