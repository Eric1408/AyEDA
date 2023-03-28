#pragma once 

#include <string>
#include <iostream>
#include <random>

template <class Key>
class DispersionFunction {
 public:
  virtual unsigned operator() (const Key&) const = 0;
  
};

/**
 * @brief Dispersion function based on the module method
 * of the key
*/
template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n) : table_size_{n} {}
  unsigned operator()(const Key&) const;
 private:
  unsigned table_size_;
};

template <class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % table_size_;
}

/**
 * @brief Dispersion function based on the division method
 * of the key
*/
template <class Key>
class fdPseudo : public DispersionFunction<Key> {
 public:
  fdPseudo(const unsigned n) : table_size_{n} {}
  unsigned operator()(const Key&) const;
 private :
  unsigned table_size_;
};

template <class Key>
unsigned fdPseudo<Key>::operator()(const Key& k) const {
  Key tmp = k;
  std::srand(tmp);
  std::cout << "chivato 2\n";
  return std::rand() % table_size_;
}

/**
 * @brief Dispersion function based on the sum of the digits
 * of the key
*/
template <class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n) : table_size_{n} {}
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
