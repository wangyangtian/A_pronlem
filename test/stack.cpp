#include <iostream>
#include <stack>
using namespace std;
int main()
{   
    #if 0
    //stack入栈和出栈
    stack<int> stk;
    //入栈
    stk.push(5);
    stk.push(10);
    stk.push(20);
    stk.push(1);
    //stack容器没有迭代器，不允许遍历
    cout<<stk.top()<<endl;//top函数返回栈顶元素
    stk.pop();
    cout<<stk.top()<<endl;
    while (!stk.empty())
    {   
        cout<<stk.top()<<endl;
        stk.pop();
    }
    cout<<stk.empty()<<endl;
    #endif
    
    stack<int> stk;
    stk.push(5);
    stk.push(10);
    stk.push(20);
    stk.push(1);
    stack<int> stk2(stk);//拷贝构造
    stack<int> stk3=stk;//拷贝构造
    stack<int> stk4;//默认构造
    stk4=stk;//=的重载
    cout<<"stk3.size()="<<stk3.size()<<endl;
    
    return 0;
}
