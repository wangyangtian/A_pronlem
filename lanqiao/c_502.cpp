#include <iostream>
using namespace std;
int main()
{
    int num=0;
    cin >> num;
    int array[num];
    float excellent_num=0;
    float pass_num=0;
    for (int i=0; i<num; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < num; i++)
    {
        if(array[i] >=85){
            excellent_num++;
        }
        if(array[i]>=60)
        pass_num++;
    }
    printf("%.0f\%\n",pass_num/num*100);
    printf("%.0f\%\n",excellent_num/num*100);
    return 0;
}