#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    int n, begin, x, y;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        memset(a[i], 0, sizeof(int) * n);
    }
    begin = a[0][0] = 1;
    x = y = 0;
    while (begin < n * n) {
        while (x + 1 < n && a[y][x + 1] == 0) {
            a[y][++x] = ++begin;
        }
        while (y + 1 < n && a[y + 1][x] == 0) {
            a[++y][x] = ++begin;
        }
        while (x - 1 >= 0 && a[y][x - 1] == 0) {
            a[y][--x] = ++begin;
        }
        while (y - 1 >= 0 && a[y - 1][x] == 0) {
            a[--y][x] = ++begin;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}