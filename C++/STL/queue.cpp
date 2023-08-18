#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{   
    //queue没有迭代器，不能进行遍历
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    cout << q.front()<<endl;
    while (q.empty()!=true)
    {
        cout<< q.front()<<" ";
        q.pop();
    }//先进先出
    cout<<endl;
    queue<int> q1(q);//拷贝构造
    queue<int> q2;
    q2=q;//重载等号操作符
        q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    q.front()=100;
    while(!q.empty())
    {
        cout<< q.front()<<endl;
        q.pop();
    }
    return 0;
}
