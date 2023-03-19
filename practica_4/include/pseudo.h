#pragma once 

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

  return std::rand() % table_size_;
}
