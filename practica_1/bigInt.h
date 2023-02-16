/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Algoritmos y Estructura de Datos Avanzados
 * @file bigInt.cc
 * @brief  
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2023-0-
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// archivo en base hexadecimal
// operador menos pero sin parametro -> cambia de signo pero no se utiliza en las expresiones porque genera ambiguedad


// lo primero a leer es ver si el numero es positivo o negativo -> el signo se guarda en otra parte
// convertir carecter char -> tenemos un vetor de tantas posiciones pero no guardamos el numero sino el digito en char (numero - '0')
// a cada numero hay que sumarle el valor del digito si es mayo que A 
// string stream -> 
// vector de char o string? -> son equivalentes
// std::map seria una estructura adecuada

// mismo algortimo para sumar, restar, mult... solo que con distinta base, si desborda la base hay un acarreo 
// a la siguiente cifra y se guarda el exeso, lo que ha desbordado

// algoritmos distintos en >> y << ya que hay que hacerlo distinto cuando las bases son mayores que 10
// las plantillas no llevan .cc

/*
  switch(base) {
    case 2: procesar<2>(...)
    case 10: procesar<10>(...)
  }
*/ 


// template <int base>
// class BigInt {
// operator BigInt<2>() {}
//}

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<size_t Base = 10>
class BigInt {
 public:
  // Constructores
  BigInt(long n = 0); 
  BigInt(std::string&); 
  BigInt(const char*);
  BigInt(const BigInt<Base>&);

  // Sobrecarga de asignacion
  BigInt<Base>& operator=(const BigInt<Base>&);

  // Sobrecarga de operadores de flujo
  friend std::istream& operator>>(std::istream&, BigInt<Base>&);
  friend std::ostream& operator<<(std::ostream& out, const BigInt<Base>& in) {
    for (int i = in.size() -1; i >= 0; i--) {
      if (in[i] >= 10) 
        out << char(in[i] + 'A' - 10);
      else 
        out << char(in[i] + '0');
    }

    return out;
  }

  // Accesor
  inline int size(void) const { return digits_.size(); }
  inline int sign(void) const { return sign_; }
  inline char operator[](int i) const { return digits_[i]; }

  // Comparacion
  friend bool operator==(const BigInt<Base>& a, const BigInt<Base>& b) { return a.digits_ == b.digits_; }
  bool operator!=(const BigInt<Base>&) const;
  friend bool operator>(const BigInt<Base>& a, const BigInt<Base>& b) { return b < a; }
  bool operator>=(const BigInt<Base>&);
  friend bool operator<(const BigInt<Base>& a, const BigInt<Base>& b) {
    int n = a.digits_.size(), m = b.digits_.size();
    if(n != m)
      return n < m;
    while(n--)
      if(a.digits[n] != b.digits[n])
        return a.digits[n] < b.digits[n];
    return false;
  }
  bool operator>=(const BigInt<Base>&) const;

  // Incremento/Decremento
  BigInt<Base>& operator++(void);
  BigInt<Base> operator++(int);
  BigInt<Base>& operator--(void);
  BigInt<Base> operator--(int);

  // Operadores aritmeticos
  friend BigInt<Base> operator+(const BigInt<Base>& a, const BigInt<Base>& b) {
    int i{0}, j{0}, carry{0};
    std::string sum;

    while (i < a.size() || j < b.size() || carry) {
      int x = a[i++];
      int y = b[j++];
      int z = x + y + carry;
      carry = z / 10;
      z = z % 10;
      if (z < 10) 
        sum.push_back(z + '0');
        //sum.push_back(z);
      else
        //sum.push_back(z); 
        sum.push_back(z + 'A' - 10);
      //sum.push_back(z | 0x00);
    }

    return BigInt(sum);
  }

  BigInt<Base> operator-(const BigInt<Base>&) const;
  BigInt<Base> operator-(void) const;
  BigInt<Base> operator*(const BigInt<Base>&) const;
  friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
  BigInt<Base> operator%(const BigInt<Base>&) const;

  // Potencia de a^b
  friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

 private:
  std::string digits_;
  int sign_;
};

// Constructores
template<size_t Base> 
BigInt<Base>::BigInt(std::string& s) {
  int n = s.size();
  for (int i = n - 1; i >= 0; i--){
    //if (s[i] > Base - 1) throw ("ERROR : Numero incorrecto"); 
    if (s[i] >= 'A' && s[i] <= 'F')
      digits_.push_back(s[i] - 'A' + 10);
    else 
      digits_.push_back(s[i] - '0');
  }
}

template<size_t Base>
BigInt<Base>::BigInt(long n) {

}

template<size_t Base> 
BigInt<Base>::BigInt(const char* n) {

}

template<size_t Base> 
BigInt<Base>::BigInt(const BigInt<Base>& n) {

}

// Operadores aritmeticos

// Sobrecarga de asignacion
template<size_t Base>
BigInt<Base>& BigInt<Base>::operator=(const BigInt<Base>& other) {
  digits_ = other.digits_;
  sign_ = other.sign_;

  return *this;
}
