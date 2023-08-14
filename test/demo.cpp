#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
int fib(int n)
{
    if(memo.at(n) ==0)
    {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n>1) {
            memo[n]=fib(n-1)+fib(n-2);
            return memo.at(n);
        }
    }
    else
        return memo.at(n);
    return memo.at(n);
}
int main()
{
    int n;
    cin>>n;
    memo.resize(n+1,0);
    cout<<fib(n)<<endl;
    return 0;
}