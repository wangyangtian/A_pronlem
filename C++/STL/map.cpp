#include <iostream>
#include <map>
using namespace std;
class Student
{
    public:
        int id;
        string name;
        Student(){}
        Student(int id, string name){this->id=id;this->name=name;}
};
int main()
{
    #if 0
    //构造一个map容器对象，存储student对象
    //键值对
    map<int,string> maps;
    maps.insert(pair<int,string>(3,"小张"));
    maps.insert(map<int,string>::value_type(1,"小李"));
    int key;
    string name;
    key=5;
    name="小赵";
    pair<int,string> p(key,name);
    maps.insert(p);
    map<int,string>::value_type v(6,"小周");
    maps.insert(v);

    maps.insert(pair<int,string>(6,"小孙"));//使用insert方法不会覆盖掉原来的键值对（安全）
    maps[2]="小田";
    maps[2]="小马";//用类似于数组的方式插入会覆盖掉原来的键值对


    map<int,string>::iterator it=maps.begin();
    for(auto a:maps)
    {
        cout<<it->second<<" ";
        it++;
    }
        

    map<int,Student> stu;
    Student s1(1,"小徐");
    stu.insert(pair<int,Student>(s1.id,s1));//通过pair的方法插入对象
    Student s2(2,"小汪");
    stu.insert(map<int,Student>::value_type(s2.id,s2));//通过value_type的方法插入对象
    Student s3(3,"小泽");
    stu[s3.id]=s3;//通过数组的方法插入值
    map<int,Student>::iterator it2=stu.begin();
    cout<<endl;
    for(auto a:stu)
    {
        cout<<it2->second.name<<" ";
        it2++;
    }
    cout<<endl;
    map<int,Student>::iterator it3;
    for(it3=stu.begin();it3!=stu.end();it3++)
    {
        pair<int,Student> p=*it3;
        int key=p.first;
        Student value=p.second;
        cout<<key<<" : "<<value.name<<endl;
    }
    //获取学号为3的同学名字
    string stu_name=maps[3];
    cout<<stu_name<<endl;
    //获取学号为10的同学名字
    stu_name=maps[10];//使用类似数组的方式，如果容器中不存在键为10的键值对，会自动创建一个键为10，值为空的键值对
    cout<<stu_name<<endl;
    #endif


    //map容器获取键所对应的值
    //方法一：使用[]    不推荐，会误删，插入不存在的键值对
    //方法二：使用find()函数：成功返回对应的迭代器，失败返回end()的返回值
    //方法三：使用at()函数，如果键值对不存在会抛出"out_of_range"异常
    map<int,string> maps;
    maps.insert(pair<int,string>(3,"小张"));
    maps.insert(pair<int,string>(10,"小李"));
    maps.insert(pair<int,string>(1,"小王"));
    maps.insert(pair<int,string>(2,"小刘"));
    maps.insert(pair<int,string>(4,"小赵"));
    map<int,string>::iterator it3;
    it3=maps.find(3);//find()函数最好
    if(it3!=maps.end())
        cout<<"3:  "<<(*it3).second<<endl;
        //cout<<"3:  "<<it3->second<<endl;
    else
        cout<<"3:  "<<"不存在"<<endl;

    it3=maps.find(12);
    if(it3==maps.end())//找不到的情况
        cout<<"12:  "<<"不存在"<<endl;

    return 0;
}