#include <iostream>
#include <deque>
using namespace std;
int main(int argc, char const *argv[])
{
    //deque与vector在操作上几乎相同，deque多两个函数
    deque<int> deq(6,6);
    deq.push_front(1);//在容器头部插入一个元素
    for(int a:deq)
        cout << a<<" ";
    cout<<endl;
    deq.pop_front();//删除容器第一个元素
        for(int a:deq)
        cout << a<<" ";
    cout<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
