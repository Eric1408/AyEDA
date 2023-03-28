#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "sequence.h"
#include "dispersion.h"
#include "exploration.h"

template <class Key>
class HashTable {
 public:
  HashTable (unsigned, DispersionFunction<Key>*, ExplorationFunction<Key>* = nullptr, unsigned = 0);

  int toPrime (int);
  bool isPrime (int);

  bool search (const Key&) const;
  bool insert (const Key&);

  static unsigned POSITION;

 private:
  std::vector<Sequence<Key>*> table_;
  unsigned hash_table_size_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned block_size_;

};

template <class Key>
unsigned HashTable<Key>::POSITION{0};

template <class Key> 
HashTable<Key>::HashTable (unsigned size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, unsigned block_size) {
  hash_table_size_ = toPrime(size);
  table_.resize(hash_table_size_);
  fd_ = fd;

  if (fe != nullptr) {
    block_size_ = block_size;
    fe_ = fe;
    for (unsigned i = 0; i < table_.size(); i++) {
      table_[i] = new Block<Key>(block_size_);
    }
  } else {
    for (unsigned i = 0; i < table_.size(); i++) {
      table_[i] = new List<Key>();
    }
  }
}

template <class Key>
bool HashTable<Key>::isPrime (int n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

template <class Key>
int HashTable<Key>::toPrime (int num) {
  while (!isPrime(num)) {
    num--;
  }
  
  return num;
}

template <class Key>
bool HashTable<Key>::search (const Key& k) const {
  unsigned pos_fd = (*fd_)(k);
  if (table_[pos_fd]->search(k)) {
    HashTable<Key>::POSITION = pos_fd;
    return true;
  }

  if (fe_ == nullptr) {
    return false;
  }

  for (unsigned i = 0; i < hash_table_size_; i++) {
    unsigned pos_fe = (*fe_)(k, i);
    unsigned pos = (pos_fd + pos_fe) % hash_table_size_; 
    if (table_[pos]->search(k)) {
      HashTable<Key>::POSITION = pos;
      return true;
    }
  }
  
  return false;
}

template <class Key>
bool HashTable<Key>::insert(const Key& k) {
  std::cout << "insert 1\n";
  unsigned pos_fd = (*fd_)(k);
  std::cout << "insert 2\n";
  if (table_[pos_fd]->insert(k)) {
    HashTable<Key>::POSITION = pos_fd;
    return true;
  }
  if (fe_ == nullptr) {
    return false;
  }

  for (unsigned i = 0; i < hash_table_size_; i++) {
    unsigned pos_fe = (*fe_)(k, i);
    unsigned pos = (pos_fd + pos_fe) % hash_table_size_;
    if (table_[pos]->insert(k)) {
      HashTable<Key>::POSITION = pos;
      return true;
    }
  }

  return false;
}
