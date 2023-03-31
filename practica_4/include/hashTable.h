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

  void print () const;

 private:
  std::vector<Sequence<Key>*> table_;
  unsigned hash_table_size_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  unsigned block_size_;

};

template <class Key>
void HashTable<Key>::print() const {
  for (unsigned i = 0; i < hash_table_size_; ++i) {
    std::cout << i << ": ";
    if (table_[i]) {
      for (unsigned j = 0; j < table_[i]->size(); ++j) {
        std::cout << table_[i]->get(j) << " ";
      }
    }
    std::cout << std::endl;
  }
}


template <class Key>
unsigned HashTable<Key>::POSITION{0};

template <class Key> 
HashTable<Key>::HashTable (unsigned size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, unsigned block_size) {
  hash_table_size_ = size;
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
  unsigned pos_fd = (*fd_)(k);
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
