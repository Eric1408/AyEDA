#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string sumar(string num1, string num2) {
    int base = 16;
    int t = 0, s, i;
    int n = num1.size(), m = num2.size();
    if(m > n)
        num1.append(m - n, 0);
    n = num1.size();
    for (i = 0; i < n;i++){
        std::cout << "i: " << i << std::endl;
        if(i < m) {
            std::cout << "  num[i] : " << short(num1[i]) << " num2[i] : " << short(num2[i]) << std::endl;
            if (num1[i] + num2[i] >= base)
                s = (num1[i] + num2[i] - base) + t;
            s = (num1[i] + num2[i] - base) + t;
            std::cout << "  s: " << s << std::endl;
        
        }
        else 
            std::cout << "  dentro de else -> i: " << i << " m: " << m << std::endl; 
            s = num1[i] + t;
        t = s / 10;
        std::cout << "t: " << t << std::endl;
        num1[i] = (s % 10);
        
    }
    if(t)
        num1.push_back(t);
    return num1;
}

int main() {
    string aux1 = "46651367647546";
    std::string num1;
    for (int i = aux1.size() -1; i >= 0; --i) {
        num1.push_back(aux1[i] - '0');
    }
    string num2;
    string aux2 = "442142117615672";
    for (int i = aux2.size() -1; i >= 0; --i) {
        num2.push_back(aux2[i] - '0');
    }
    string resultado = sumar(num1, num2);
    for (int i = resultado.size() -1; i>=0; --i) {
        cout << char(resultado[i] + '0');
    }
    cout << endl; // imprime 13F54
    return 0;
}


