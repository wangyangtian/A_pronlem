#include <iostream>
#include <set>
using namespace std;
    class CStudent{
        public:
        CStudent(int iID,string strName)
        {
            m_iID = iID;
            m_strName = strName;
        }
        int m_iID;
        string m_strName;
    };
    //伪函数类
    class StuFunctor
    {
    public:
        bool operator()(const CStudent &s1,const CStudent &s2)
        {
            return s1.m_iID<s2.m_iID;
        }
    };
int main()
{
    /*
    set是一个集合容器，其中所包含的元素是唯一的，集合中的元素按一定的顺序排列。元素插入过程是按排
        序规则插入，所以不能指定插入位置。

    set采用红黑树变体的数据结构实现，红黑树属于平衡二叉树。在插入操作和删除操作上比vector快。

    set不可以直接存取元素。(不可以使用at.(pos)与[]操作符) 。

    multiset与set的区别: set支持唯一 键值,每个元素值只能出现一次;而multiset中同一值可以出现多次。

    不可以直接修改set或multiset容器中的元素值，因为该类容器是自动排序的。如果希望修改一个元素值,
        必须先删除原有的元素，再插入新的元素。
    */
   #if 0
    set<int> s1;//set容器默认升序排序
    s1.insert(3);
    s1.insert(1);
    s1.insert(5);
    s1.insert(7);
    set<int>::iterator it;
    // for(it = s1.begin(); it != s1.end();it++)
    //     cout<<*it<<" ";
    // cout<<endl;
    // set<int>::reverse_iterator it2;//反向迭代器
    // for(it2=s1.rbegin();it2!=s1.rend();it2++)
    //     cout<<*it2<<" ";
    // cout<<endl;
    // s1.erase(1);//删除指定的值
    // for(it2=s1.rbegin();it2!=s1.rend();it2++)
    //     cout<<*it2<<" ";
    // cout<<endl;
    it=s1.begin();
    it=s1.erase(it);//删除第一个元素（最小）
    for(it = s1.begin(); it != s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<*it<<endl;
    it=s1.end();
    it--;
    it=s1.erase(it);//删除最后一个元素（最大）
    for(it = s1.begin(); it != s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;   
    cout<<*it<<endl;
    //set容器不支持反向迭代器删除元素
    it++;//it++后迭代器重新指向set容器的第一个元素
    cout<<*it<<endl;
    //erase函数如果需要删除的元素在set中返回TRUE，否则返回FALSE
    cout<<s1.erase(100)<<endl;

    #endif

    #if 0
    /*
    set<int,less<int>> setIntA;     该容器是按升序方式排列元素。
    set<int,greater<int>> setIntB;  该容器是按降序方式排列元素。
    */
    set<int,greater<int>> s1;
    set<int,less<int>> s2;
    s1.insert(1);
    s1.insert(5);
    s1.insert(3);
    s1.insert(9);
    s1.insert(7);

    s2.insert(1);
    s2.insert(5);
    s2.insert(3);
    s2.insert(9);
    s2.insert(7);
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(it=s2.begin();it!=s2.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    #endif
    #if 0
    //定义一个容器实现存储学生信息
    set<CStudent,StuFunctor> stu;
    stu.insert(CStudent(10,"xiaoming"));
    stu.insert(CStudent(6,"xiaodong"));
    stu.insert(CStudent(8,"xiaowang"));
    stu.insert(CStudent(12,"xaioli"));
    set<CStudent,StuFunctor>::iterator it1;
    for(it1=stu.begin();it1!=stu.end();it1++)
        cout<<it1->m_iID<<" "<<it1->m_strName<<","<<endl;
    #endif
    #if 0
    set<int> s1;
    s1.insert(3);
    s1.insert(1);
    s1.insert(5);
    s1.insert(7);
    set<int>::iterator it;
    it=s1.find(7);
    cout<<*it<<endl;
    it=s1.upper_bound(3);//返回第一个>elem元素的迭代器
    cout<<*it<<endl;
    it=s1.lower_bound(3);
    cout<<*it<<endl;//返回第一个>=elem元素的迭代器
    #endif


    multiset<int> s2;
    s2.insert(3);
    s2.insert(1);
    s2.insert(5);
    s2.insert(7);
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    s2.insert(7);
    multiset<int>::iterator it;
    pair<set<int>::iterator,set<int>::iterator> p=s2.equal_range(5);
    //set.equal_range(elem)返回与elem相等的上下限的两个迭代器，上限是闭区间，下限是开区间，如[beg,end)
    //函数返回的两个迭代器，而这两个迭代器被封装在pair中。
    //pair可将两个值视为一个单元。
    //pair<T1,T2>存放的两个值类型可以不一样，如T1为int，T2为float。T1,T2也可以是自定义类型。
    //pair.first是pair里面的第一个值，是T1类型。
    //pair.second是pair里面的第二个值，是T2类型。
    cout<<s2.count(5)<<endl;
    int count=0;
    while(p.first!=p.second)
    {
        p.first++;
        count++;
    }
    cout<<count<<endl;
    it=s2.find(5);
    it--;
    cout<<*it<<endl;
    return 0;
}