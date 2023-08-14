#include <iostream>   
using namespace std;
bool isLeap(int y){
    return (y%4==0&&y%100!=0)||(y%400==0);
}

bool check(int year,int month,int day){
    if(month>12||month==0) return false;
    if(day>31) return false;
    if(month==2){
        if(isLeap(year)&&day>29)
            return false;
        if(!isLeap(year)&&day>28)
            return false;
    }
    if(month==4||month==6||month==9||month==11){
        if(day>30) return false;
    }
    return true;
}
int main()
{
  int data=10000000;
  int temp=0;

  cin >> data;
  for(int i=data;;i++)
  {
    int num1=i%10;
    int num_1=i/10;
    int num2=num_1%10;
    int num_2=num_1/10;
    int num3=num_2%10;
    int num_3=num_2/10;
    int num4=num_3%10;
    int num_4=num_3/10;
    int num5=num_4%10;
    int num_5=num_4/10;
    int num6=num_5%10;
    int num_6=num_5/10;
    int num7=num_6%10;
    int num_7=num_6/10;
    int num8=num_7%10;
    int year,month,day;
    year=i/10000;
    month=(i%10000)/100;
    day=i%100;
    if(check(year,month,day)){
      if ((num1==num8)&&(num2==num7)&&(num3==num6)&&(num4==num5))
    {
      
      printf("%d\n",i);
      temp=i;
      break;
    }
    }}
  for(int i=temp;;i++)
  {
    int num1=i%10;
    int num_1=i/10;
    int num2=num_1%10;
    int num_2=num_1/10;
    int num3=num_2%10;
    int num_3=num_2/10;
    int num4=num_3%10;
    int num_4=num_3/10;
    int num5=num_4%10;
    int num_5=num_4/10;
    int num6=num_5%10;
    int num_6=num_5/10;
    int num7=num_6%10;
    int num_7=num_6/10;
    int num8=num_7%10;
    int year,month,day;
    year=i/10000;
    month=(i%10000)/100;
    day=i%100;
    if ((num1==num8)&&(num2==num7)&&(num3==num6)&&(num4==num5)&&(num1==num3)&&(num2==num4))
    {
      if(check(year,month,day))
      printf("%d",i);
      break;
    }
    }
  return 0;
}