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

#pragma once

#include <iostream>
#include <string>
#include <vector>

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

template<size_t Base> class BigInt {
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
  friend std::ostream& operator<<(std::ostream&, const Bigint<Base>&);

  // Accesor
  int sign(void) const;
  char operator[](int) const;

  // Comparacion
  friend bool operator==(const BigInt<Base>&, const BigInt<Base>&);
  bool operator!=(const BigInt<Base>&) const;
  friend bool operator>(cosnt BigInt<Base>&, const BigInt<Base>&);
  bool operator>=(const BigInt<Base>&);
  friend bool operator<(const BigInt<Base>&, const BigInt<Base>&);
  bool operator>=(const BigInt<Base>&);

  // Incremento/Decremento
  BigInt<Base>& operator++(void);
  BigInt<Base> operator++(int);
  BigInt<Base>& operator--(void);
  BigInt<Base> operator--(int);

  // Operadores aritmeticos
  friend BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);
  BigInt<Base> operator-(const BigInt<Base>&) const;
  bigInt<Base> operator-(void) const;
  Bigint<Base> operator*(const BigInt<Base>&) const;
  friend BigInt<Base> operator/(const BigInt<Base>&, cosnt BigInt<Base>&);
  BigInt<Base> operator%(const BigInt<Base>&) const;

  // Potencia de a^b
  friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

 private:
  std::vector<char> digits_;
}

template<size_t Base> BigInt<Base>::BigInt{
  
}
