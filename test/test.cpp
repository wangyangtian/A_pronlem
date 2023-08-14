#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int fib(int n) {
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return 1;
    } 
    else if (memo[n] != 0) {
        return memo[n];
    } 
    else {
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
}

int main() {
    int n;
    cin >> n;
    memo.resize(n + 1, 0);
    cout << fib(n) << endl;
    return 0;
}