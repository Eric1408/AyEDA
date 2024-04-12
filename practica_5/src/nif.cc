#include "nif.h"


void NIF::print() const {
  std::string nifLength = std::to_string(nif_);
  
  // if nif_ begins with 0, it will be removed
  if (nifLength.size() < 8) {
    int zerosToAdd = 8 - nifLength.size();
    for (int i = 0; i < zerosToAdd; i++) {
      std::cout << "0";
    }
  }

  std::cout << nif_ << "-" << letter_ << std::endl;
}


bool NIF::validateNIF(const std::string& nif) const {
  if (nif.size() != 9) {
    return false;
  }
  for (int i = 0; i < 8; i++) {
    if (!isdigit(nif[i])) {
      return false;
    }
  }
  if (!isalpha(nif[8])) {
    return false;
  }
  return true;
}

NIF::NIF(const std::string& nif) {
  if (validateNIF(nif)) {
    nif_ = std::stoi(nif.substr(0, 8));
    letter_ = nif[8];
  } else {
    std::cerr << "Invalid NIF" << std::endl;
  }
}


std::ostream& operator<<(std::ostream& os, const NIF& nif) {
  os << nif.getNif() << "-" << nif.getLetter();
  return os;
}


NIF NIF::random() {
  std::string nif;
  
  // Generar un número de 8 dígitos aleatorio
  for (int i = 0; i < 8; i++) {
    nif += std::to_string(rand() % 10);
  }

  // Calcular la letra de control
  const std::string letras_control = "TRWAGMYFPDXBNJZSQVHLCKE";
  int sum = 0;
  for (char c : nif) {
    sum += c - '0';
  }
  char letra_control = letras_control[sum % 23];

  nif += letra_control;
  //std::cout << nif << std::endl;
  return NIF(nif);
}
