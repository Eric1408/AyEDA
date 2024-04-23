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

  int operator/(int nif) const { return nif_ / nif; }

  int getNif() const { return nif_; }
  char getLetter() const { return letter_; }


  friend std::ostream& operator<<(std::ostream&, const NIF&);

  static NIF random();
};
