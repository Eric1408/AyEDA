#pragma once 

#include <iostream>
#include <vector>


template <class Key>
class Sequence {
 public:
  virtual bool search(const Key&) const = 0;
  virtual bool insert(const Key&) = 0;
  virtual bool isFull() const = 0;

  virtual unsigned size() const = 0;
  virtual Key get(unsigned) const = 0;

  virtual Key operator[](const size_t&) const = 0;
 protected:
  std::vector<Key> data_;
};


/**
 * @brief Block class
*/
template <class Key>
class Block : public Sequence<Key> {
 public:
  Block() = default;
  Block(unsigned i) : blockSize_{i} { this->data_.reserve(i);}

  bool search(const Key&) const;
  bool insert(const Key&);
  bool isFull() const;

  unsigned size() const { return Sequence<Key>::data_.size(); }
  Key get(unsigned i) const { return Sequence<Key>::data_[i]; }
  void set(unsigned i, const Key& k) { Sequence<Key>::data_[i] = k; }

  Key operator[](const size_t& i) const { return Sequence<Key>::data_[i]; }
 private:
  unsigned blockSize_;
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
  if (!search(k) && !isFull()) {
    Sequence<Key>::data_.push_back(k);
    return true;
  }
  return false;
}

template <class Key>
bool Block<Key>::isFull() const {
  return Sequence<Key>::data_.size() == blockSize_;
}
