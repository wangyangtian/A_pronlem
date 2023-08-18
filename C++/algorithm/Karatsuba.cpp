#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long Karatsuba(string x, string y) {
    if (x.length() < 2 || y.length() < 2) 
        return stoi(x) * stoi(y);
    else {
        int n1 = x.length();
        int n2 = y.length();
        int n = max(n1, n2);
        int half = n / 2;
        
        string a = x.substr(0, half);
        string b = x.substr(half, n1 - half);
        string c = y.substr(0, half);
        string d = y.substr(half, n2 - half);

        long a_int = stol(a);
        long b_int = stol(b);
        long c_int = stol(c);
        long d_int = stol(d);

        long long z0 = Karatsuba(a, c);
        long long z1 = Karatsuba(b, d);
        long long z2 = Karatsuba(to_string(a_int + b_int), to_string(c_int + d_int));
        z2 = z2 - z0 - z1;

        return z0 * pow(10, (2 * (n1-half))) + z2 * pow(10, (n2-half)) + z1;
    }
}

int main() {
    string num1, num2;
    cout<<"Enter two numbers: ";
    cin >> num1 >> num2;
    cout << Karatsuba(num1, num2) << endl;
    return 0;
}