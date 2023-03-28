#pragma once 

#include <iostream>
#include <regex>

#include "hashTable.h"
#include "dispersion.h"
#include "sequence.h"
#include "exploration.h"

class Menu {
 private:
  static const std::regex fdPattern;

  static const std::string MODULE;
  static const std::string SUM;
  static const std::string PSEUDO;

  static const std::string BLOCK;
  static const std::string LIST;

  static const std::string LINEAL_EXP;
  static const std::string DOUBLE_EXP;
  static const std::string DOUBLE_HASH_EXP;
  static const std::string REHASH_EXP;

  HashTable<long>* hash_table_;

 public:
  Menu ();
  void start ();
  void insert ();
  void search ();
  void stop ();
};
