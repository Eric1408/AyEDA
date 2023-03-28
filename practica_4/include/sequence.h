#pragma once 

#include <iostream>
#include <vector>

#include "exploration.h"
template <class Key>
class Sequence {
 public:
  virtual bool search (const Key&) const = 0;
  virtual bool insert (const Key&) = 0;
  virtual bool isFull () const = 0;
 protected:
  std::vector<Key> data_;
};

/**
 * @brief List class
*/
template <class Key>
class List : public Sequence<Key> {
 public:
  List () = default;
  bool search (const Key&) const;
  bool insert (const Key&);
  bool isFull () const { return false; }

};

template <class Key>
bool List<Key>::search (const Key& k) const {
  for (unsigned i = 0; i < Sequence<Key>::data_.size(); i++) {
    if (Sequence<Key>::data_[i] == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool List<Key>::insert(const Key& k) {
  if (!search(k)) {
    Sequence<Key>::data_.push_back(k);
    return true;
  }
  return false;
}

/**
 * @brief Block class
*/
template <class Key>
class Block : public Sequence<Key> {
 public:
  Block (unsigned i) : block_size_{i} {}
  bool search (const Key&) const;
  bool insert (const Key&);
  bool isFull () const;

 private:
  unsigned block_size_;
};

template <class Key>
bool Block<Key>::search(const Key& k) const {
  for (auto i : Sequence<Key>::data_) {
    if (i == k) {
      return true;
    }
  }
  return false;
}

template <class Key>
bool Block<Key>::insert(const Key& k) {
  std::cout << "chivato insert en sequence 1\n";
  if (!search(k) && !isFull()) {
    std::cout << "chivato insert en sequence 2\n";
    Sequence<Key>::data_.push_back(k);
    return true;
  }
  return false;
}

template <class Key>
bool Block<Key>::isFull() const {
  return Sequence<Key>::data_.size() == block_size_;
}
