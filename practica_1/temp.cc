#include <iostream>
#include <string>

using namespace std;

int main() {
  string a,b,aux, baux, sum;
  // Lee los dos números octales a sumar
  cout << "Ingresa el primer número octal: ";
  cin >> aux;
  cout << "Ingresa el segundo número octal: ";
  cin >> baux;
  for (int i = aux.size()-1; i >=0 ; --i) {
    if (aux[i] >= 'A') {
      std::cout << "dentro\n";
      aux[i] = aux[i] - 'A' + 10;
      a.push_back(aux[i]);
    } else {
      aux[i] = aux[i] - '0';
      a.push_back(aux[i]);
    } 
  }
  for (int i = baux.size()-1; i >=0; --i) {
    if (baux[i] >= 'A') {
      std::cout << "dentro\n";
      baux[i] = baux[i] - 'A' + 10;
      b.push_back(baux[i]);
    } else {
      baux[i] = baux[i] - '0';
      b.push_back(baux[i]);
    } 
  }
  int carry = 0;
  int i = 0;
  int j = 0;
  int n = a.size();
  int m = b.size();

  // Comienza a sumar los dígitos menos significativos de ambos números
  while (i < a.size() || j < b.size() || carry) {
    int x = a[i++];
    int y = b[j++];
    int z = x + y + carry;
    std::cout << "z + : " << z << std::endl;
    carry = z / 16;
    std::cout << "carry: " <<  carry << std::endl;
    z = z % 16;
    std::cout << "z % : " << z << std::endl;
    sum.push_back(z | 0x00);
  }
  // Imprime el resultado
  cout << "La suma es: " << endl;
  for (int i = sum.size()-1; i >= 0 ; --i) {
    std::cout << short(sum[i] );
    if (sum[i] >= 10) {
      //std::cout << "dentro de f \n";
      //std::cout << char(sum[i] + 'A' -10);
    } else {
      //std::cout << "dentro de a \n";
      //std::cout << char(sum[i] + '0');
      
    }
  }

  return 0;
}
