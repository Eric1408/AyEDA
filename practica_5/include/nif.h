#pragma once

#include <iostream>
#include <random>


class NIF {
 private:
  int nif_;
  char letter_;
  bool validateNIF(const std::string&) const;

 public:
  NIF(const std::string&);
  void print() const;

  bool operator<(const NIF& nif) const { return nif_ < nif.nif_; }
  bool operator>(const NIF& nif) const { return nif_ > nif.nif_; }
  bool operator==(const NIF& nif) const { return nif_ == nif.nif_; }
  bool operator!=(const NIF& nif) const { return nif_ != nif.nif_; } 
  bool operator<=(const NIF& nif) const { return nif_ <= nif.nif_; }
  bool operator>=(const NIF& nif) const { return nif_ >= nif.nif_; }

  static NIF random();

  friend std::ostream& operator<<(std::ostream&, const NIF&);
};