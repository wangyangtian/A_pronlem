#include <iostream>
using namespace std;
int fun(int x)
{
    return x / 4 + (x + 1) / 2;
}
int main()
{
    int l, r;
    cin >> l >> r;
    cout << fun(r) - fun(l - 1);
    return 0;
}