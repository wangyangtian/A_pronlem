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
    //����һ��map�������󣬴洢student����
    //��ֵ��
    map<int,string> maps;
    maps.insert(pair<int,string>(3,"С��"));
    maps.insert(map<int,string>::value_type(1,"С��"));
    int key;
    string name;
    key=5;
    name="С��";
    pair<int,string> p(key,name);
    maps.insert(p);
    map<int,string>::value_type v(6,"С��");
    maps.insert(v);

    maps.insert(pair<int,string>(6,"С��"));//ʹ��insert�������Ḳ�ǵ�ԭ���ļ�ֵ�ԣ���ȫ��
    maps[2]="С��";
    maps[2]="С��";//������������ķ�ʽ����Ḳ�ǵ�ԭ���ļ�ֵ��


    map<int,string>::iterator it=maps.begin();
    for(auto a:maps)
    {
        cout<<it->second<<" ";
        it++;
    }
        

    map<int,Student> stu;
    Student s1(1,"С��");
    stu.insert(pair<int,Student>(s1.id,s1));//ͨ��pair�ķ����������
    Student s2(2,"С��");
    stu.insert(map<int,Student>::value_type(s2.id,s2));//ͨ��value_type�ķ����������
    Student s3(3,"С��");
    stu[s3.id]=s3;//ͨ������ķ�������ֵ
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
    //��ȡѧ��Ϊ3��ͬѧ����
    string stu_name=maps[3];
    cout<<stu_name<<endl;
    //��ȡѧ��Ϊ10��ͬѧ����
    stu_name=maps[10];//ʹ����������ķ�ʽ����������в����ڼ�Ϊ10�ļ�ֵ�ԣ����Զ�����һ����Ϊ10��ֵΪ�յļ�ֵ��
    cout<<stu_name<<endl;
    #endif


    //map������ȡ������Ӧ��ֵ
    //����һ��ʹ��[]    ���Ƽ�������ɾ�����벻���ڵļ�ֵ��
    //��������ʹ��find()�������ɹ����ض�Ӧ�ĵ�������ʧ�ܷ���end()�ķ���ֵ
    //��������ʹ��at()�����������ֵ�Բ����ڻ��׳�"out_of_range"�쳣
    map<int,string> maps;
    maps.insert(pair<int,string>(3,"С��"));
    maps.insert(pair<int,string>(10,"С��"));
    maps.insert(pair<int,string>(1,"С��"));
    maps.insert(pair<int,string>(2,"С��"));
    maps.insert(pair<int,string>(4,"С��"));
    map<int,string>::iterator it3;
    it3=maps.find(3);//find()�������
    if(it3!=maps.end())
        cout<<"3:  "<<(*it3).second<<endl;
        //cout<<"3:  "<<it3->second<<endl;
    else
        cout<<"3:  "<<"������"<<endl;

    it3=maps.find(12);
    if(it3==maps.end())//�Ҳ��������
        cout<<"12:  "<<"������"<<endl;

    return 0;
}