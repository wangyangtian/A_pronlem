#include <iostream>
#include <vector>
using namespace std;
int main()
{
    #if 0
    int i[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //vector的构造
    vector<int> v1(i, i + 11);//vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中
    vector<int> v2(3, 6);//创建一个vector，元素个数为nSize,且值均为t
    vector<int> v3(v1);//vector(const vector&):复制构造函数
    for (int a : v3)
    {
        cout << a << " ";
    }
    #endif

    //vector的赋值
    #if 0
    vector<int> v1,v2,v3;
    int i[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    v1.assign(i,i+5);//将数组i中所有元素赋值给v1容器
    for(int a:v1)
        cout <<a<<" ";
    cout<<endl;
    v2.assign(v1.begin(),v1.end());//将v1中所有元素赋值给v2容器
    for(int a:v2)
        cout <<a<<" ";
    cout<<endl;
    v3.assign(v1.begin()+2,v1.end()-4);
    for(int a:v3)
        cout <<a<<" ";
    cout<<endl;
    v3.swap(v1);//交换两个容器的元素
    for(int a:v3)
        cout <<a<<" ";
    cout<<endl;
    #endif

    //vector 大小
    #if 0
    vector<int> v1;
    cout<<v1.size()<<endl;//返回容器中元素的个数
    cout<<v1.empty()<<endl;//判断容器是否为空
    int i[]={0,1,2,3,4};
    v1.assign(i,i+5);
    //vector.resize(num);           //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除。
    //vector.resize(num, elem);     //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除。

    v1.resize(10);//将容器长度变长，且默认值是0
    for(int a:v1)
    {
        cout<<a<<" ";
    }
    v1.resize(3);//将容器长度变短，则截去后面多余的元素
    for(int a:v1)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    v1.resize(10,6);//将容器长度变长，且扩展的值为指定值6
    for(int a:v1)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    #endif
    
    //vector元素访问方式
    #if 0
    int i[]={1,2,3,4};
    vector<int> v1(i,i+4);
    v1.at(2)=10;
    for(int a:v1)
    {
        cout<<a<<" ";
    }
    //使用at异常时会抛出错误
//terminate called after throwing an instance of 'std::out_of_range'
//what():  vector::_M_range_check: __n (which is 8) >= this->size() (which is 4)
    #endif
    #if 0
    //vector插入
    int i[]={1,2,3,4};
    vector<int> v1(i,i+4);
    v1.push_back(10);//从末尾插入一个元素
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;
    v1.pop_back();//删除末尾的元素
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;
    //vector.insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。

    v1.insert(v1.begin()+2,100);//注意：第一个参数pos不是下标，应该是指针
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;
    //vector.insert(pos,n,elem);l/在pos位置插入n个elem数据，无返回值。
    v1.insert(v1.begin()+3,3,1000);
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;
    //vector.insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
    int b[]={10,20,30,40,50};
    v1.insert(v1.begin()+2,b,b+3);
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;
    //同样可以对容器进行操作
    vector<int> v2(b,b+4);
    v1.insert(v1.begin()+7,v2.begin(),v2.end()-1);
    for(int a:v1)
        cout<<a<<" ";
    cout<<endl;

    #endif

    #if 0
    //迭代器
    int i[]={1,2,3,4,5};
    vector<int> v1;
    v1.assign(i,i+5);
    vector<int>::iterator it;
    it=v1.begin();
    //通过循环方式使用迭代器遍历v1中所有元素
    for(it=v1.begin();it!=v1.end();it++)
        cout<<*it<<" ";
    cout<<endl; 
    #endif
    
    #if 0
    //插入元素导致迭代器失效
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int>::iterator it =v1.begin()+3;
    it=v1.insert(it,8);
    cout<<*it<<endl;
    #endif


    //删除元素导致迭代器失效
    vector<int> v2={1,2,3,3,3,3,3,5,6};
    vector<int>::iterator it;
    for (it=v2.begin();it!=v2.end();)
    {
        if(*it==3)
            it = v2.erase(it);
        else
        it++;
    }
    for (it=v2.begin();it!=v2.end();it++)
        cout<<*it<<endl;
    cout<<endl;
    return 0;
}