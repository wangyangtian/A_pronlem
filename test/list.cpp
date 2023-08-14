#include <iostream>
#include <list>
using namespace std;
int main(int argc, char const *argv[])
{
    #if 0
    //list容器
    list<int> lst;
    lst.push_back(10);
    lst.push_front(20);
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    int x= lst.front();
    int y= lst.back();
    cout<<x<<" "<<y<<endl;
    lst.front() =100;
    lst.back() =200;
        for (it = lst.begin(); it != lst.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    lst.pop_back();
    lst.pop_front();
    #endif

    #if 0
    //list容器的反向迭代器
    list<int> lst;
    lst.push_back(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.push_front(40);
    list<int>::reverse_iterator it1;
    for (it1=lst.rbegin(); it1!=lst.rend(); it1++)
        cout<<*it1<<" ";
    cout<<endl;
    #endif

    #if 0 
    //list容器带参数构造

    //list(n,elem);     //构造函数将n个elem拷贝给本身。
    list<int> lst2(5,5);

    //list(beg,end);    //构造函数将[beg,end]区间中的元素拷贝给本身
    //list<int> lst3(lst2.begin(),lst2.begin()+2);    //错误
    list<int>::iterator beg=lst2.begin();
    list<int>::iterator end=lst2.begin();
    end++;
    end++;
    end++;
    list<int> lst3(beg,end);
    list<int>::iterator it;
    for(it=lst3.begin();it!=lst3.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    //list(const list &lst);    //拷贝构造函数。
    list<int> lst4(lst2);
    #endif

    #if 0
    //list容器的赋值
    list<int> lst={10,20,30,40,50};
    list<int> lst4,lst5;
    lst5.push_back(5);
    lst5.push_back(6);

    lst4.assign(lst.begin(),lst.end());
    lst4.assign(4,6);//覆盖，不是追加
    for(int a:lst4)
        cout<<a<<" ";
    cout<<endl;

    lst4.swap(lst5);
        for(int a:lst4)
        cout<<a<<" ";
    #endif

    #if 0
    //list容器的大小
    //list.size();//返回容器中元素的个数
    //list.empty());//判断容器是否为空
    //list.resize(num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                        //如果容器变短，则末尾超出容器长度的元素被删除。
    //list.resize(num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置
                                //如果容器变短，则末尾超出容器长度的元素被删除。
    list<int> lst={10,20,30,40,50};
    list<int> lst4,lst5;
    lst5.push_back(5);
    lst5.push_back(6);

    lst4.assign(lst.begin(),lst.end());
    lst4.assign(4,6);//覆盖，不是追加

    cout<<lst4.size()<<" ";
    #endif

    #if 0
    //list容器插入
    list<int> lst5={10,20,30,40,50};
    list<int>::iterator it=lst5.begin();
    it++;
    lst5.insert(it,40);//在list容器中的第二个位置插入一个40
    for(int a:lst5)
        cout<<a<<" ";
    cout<<endl;

    //在30的位置插入一个50
    for(it=lst5.begin();it!=lst5.end();it++)
    {
        if(*it==30)
        break;
    }
    if(it!=lst5.end())
        lst5.insert(it,50);
    for(int a:lst5)
        cout<<a<<" ";
    cout<<endl;

    #endif

    #if 0
    //list容器的删除
    list<int> lst={10,20,30,40,40};
    list<int>::iterator it=lst.begin();
    it++;
    it=lst.erase(it);
    cout<<*it<<endl;//删除pos位置的数据，返回下一个数据的位置。
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;
    lst.remove(40);//删除所有30
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;
    lst.push_back(40);
    lst.push_back(50);
    lst.push_back(60);
    list<int>::iterator it2=lst.end();
    it2--;
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;
    lst.erase(it,it2);
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;
    lst.clear();//清空函数

    #endif

    #if 0 
    //list容器的反转
    list<int> lst={10,20,30,40,40};
    lst.reverse();
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;
    #endif

    //list容器失效
    list<int> lst={1,2,3,3,3,3,4,5};
    list<int>::iterator it;

    for(it=lst.begin();it!=lst.end();)
    {
        if(*it == 3)
            it=lst.erase(it);
        else
            it++;
    }
    for(int a:lst)
        cout<<a<<" ";
    cout<<endl;   
    return 0;
}
