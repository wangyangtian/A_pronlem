#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, flag = 0;
    cin >> a >> b;
    for (int x = a; x <= b; x++)
    {
        for (int j = 0;; j++)
        {
            int i = floor(sqrt(x+j*j));
            if (x + j * j == i * i)
            {
                flag += 1;
                break;
            }
            if (i*i-j*j>x)
            {
                break;
            }
            
        }
    }
    cout << flag;
    return 0;
}