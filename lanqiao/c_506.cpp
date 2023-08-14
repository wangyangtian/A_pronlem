//504
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num_a=0,num_b=0,num_c=0,num_d=0,num_e=0,num_f=0,num_g=0,num_h=0,num_i=0,num_j=0,num_k=0,num_l=0,num_m=0,
    num_n=0,num_o=0,num_p=0,num_q=0,num_r=0,num_s=0,num_t=0,num_u=0,num_v=0,num_w=0,num_x=0,num_y=0,num_z=0;
    int len = s.size();
    char *c = new char[len+1];
    strcpy(c, s.c_str());
    for (int i=0; i<len; i++)
    {
        if(c[i] =='a')
        num_a++;
        else if (c[i]=='b')
        num_b++;
        else if (c[i] == 'c')
        num_c++;
        else if (c[i] == 'd')
        num_d++;
        else if (c[i] == 'e')
        num_e++;
        else if (c[i] == 'f')
        num_f++;
        else if (c[i] == 'g')
        num_g++;
        else if (c[i] == 'h')
        num_h++;
        else if (c[i] == 'i')
        num_i++;
        else if (c[i] == 'j')
        num_j++;
        else if (c[i] == 'k')
        num_k++;
        else if (c[i] == 'l')
        num_l++;
        else if (c[i] == 'm')
        num_m++;
        else if (c[i] == 'n')
        num_n++;
        else if (c[i] == 'o')
        num_o++;
        else if (c[i] == 'p')
        num_p++;
        else if (c[i] == 'q')
        num_q++;
        else if (c[i] == 'r')
        num_r++;
        else if (c[i] == 's')
        num_s++;
        else if (c[i] == 't')
        num_t++;
        else if (c[i] == 'u')
        num_u++;
        else if (c[i] == 'v')
        num_v++;
        else if (c[i] == 'w')
        num_w++;
        else if (c[i] == 'x')
        num_x++;
        else if (c[i] == 'y')
        num_y++;
        else if (c[i] == 'z')
        num_z++;        
    }
    int max_num = max({num_a, num_b, num_c, num_d, num_e, num_f, num_g, num_h, num_i, num_j, num_k, num_l, num_m, num_n, num_o, num_p, num_q, num_r, num_s, num_t, num_u, num_v, num_w, num_x, num_y, num_z});
    char max_char;
    int counts[] = {num_a, num_b, num_c, num_d, num_e, num_f, num_g, num_h, num_i, num_j, num_k, num_l, num_m, num_n, num_o, num_p, num_q, num_r, num_s, num_t, num_u, num_v, num_w, num_x, num_y, num_z};
    for(int i = 0; i < 26; i++) {
        if(counts[i] == max_num) {
            max_char = 'a' + i;
            break;
        }
    }
    cout << "The maximum count is: " << max_num << " and the character is: " << max_char << endl;

    return 0;
}
