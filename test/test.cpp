// #include <iostream>

// using namespace std;

// void merge(int arr[], int p, int q, int r) {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int *L = new int[n1];
//     int *R = new int[n2];
    
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[q + j + 1];

//     int i = 0;
//     int j = 0;
//     int k = p;
    
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
    
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
    
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }

//     delete[] L;
//     delete[] R;
// }

// void mergeSort(int arr[], int p, int r) {
//     if (p < r) {
//         int q = (p + r) / 2;
//         mergeSort(arr, p, q);
//         mergeSort(arr, q + 1, r);
//         merge(arr, p, q, r);
//     }
// }

// int main() {
//     int a[] = {1, 5, 7, 4, 2, 0, 22, 3, 1};
//     mergeSort(a, 0, 8);
//     for (int i = 0; i < 9; i++) {
//         cout << a[i] << " ";
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;

// long long Karatsuba(string x, string y) {
//     if (x.length() < 2 || y.length() < 2)
//         return stoi(x) * stoi(y);
//     else {
//         int n1 = x.length();
//         int n2 = y.length();
//         int n = max(n1, n2);
//         int half = n / 2;

//         string a = x.substr(0, half);
//         string b = x.substr(half, n1 - half);
//         string c = y.substr(0, half);
//         string d = y.substr(half, n2 - half);
        
//         long long a_int = stol(a);
//         long long b_int = stol(b);
//         long long c_int = stol(c);
//         long long d_int = stol(d);

//         long long z0 = Karatsuba(a, c);
//         long long z1 = Karatsuba(b, d);
//         long long z2 = Karatsuba(to_string(a_int + b_int), to_string(c_int + d_int));
//         z2 = z2 - z0 - z1;

//         return z0 * pow(10, (2 * (n1-half))) + z2 * pow(10, (n2 - half)) + z1;
//     }
// }

// int main() {
//     string test[] = { "12","123","1234","12345","123456" };
//     for (string i : test) {
//         cout << Karatsuba(i, i) << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     vector<vector<int>> vv;
//     vv.push_back({1});
//     vv.push_back({1,1,1});
//     vv.push_back({1,1,1});
//     vector<vector<int>>::iterator it=vv.end()-1;
//     vector<int>::iterator it1=it->begin();
//     cout<<*it1;
//     return 0;
// }
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<vector<long>> vv;
//     vv.push_back({1});
//     vv.push_back({1, 1});
    
//     long n;
//     cin >> n;
    
//     if (n == 1) {
//         cout <<1<< endl;
//     } else {
//         long row = 2;
//         while (true) {
//             vector<long> v;
//             v.push_back(1);
            
//             for (int j = 0; j < row - 1; j++) {
//                 v.push_back(vv[row - 1][j] + vv[row - 1][j + 1]);
//             }
            
//             v.push_back(1);
//             vv.push_back(v);
            
//             for (int col = 0; col < v.size(); col++) {
//                 if (v[col] == n) {
//                     cout <<row*(row+1)/2+col+1<< endl;
//                     return 0;
//                 }
//             }

//             row++;
//         }
//     }
    
//     return 0;
// }
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int grid_size=grid.size();
        int i=0,j=0,step=0;
        if(grid[0][0]!=0)
            return false;
        while(grid[i][j]!=grid_size*grid_size-1)
        {
            {
                if((grid[i][j]==grid[i+1][j+2]-1)&&((i+1)<grid_size)&&((j+2)<grid_size))
                {
                    i=i+1;
                    j=j+2;
                    step++;
                }
                else if((grid[i][j]==grid[i-1][j-2]-1)&&(i-1>=0)&&(j-2>=0))
                {
                    i=i-1;
                    j=j-2;
                    step++;
                }
                else if((grid[i][j]==grid[i+1][j-2]-1)&&(j-2>=0))
                {
                    i=i+1;
                    j=j-2;
                    step++;
                }
                else if((grid[i][j]==grid[i-1][j+2]-1)&&(i-1>=0)&&(j+2<grid_size))
                {
                    i=i-1;
                    j=j+2;
                    step++;
                }
                else if((grid[i][j]==grid[i+2][j+1]-1)&&(i+2<grid_size)&&(j+1)<grid_size)
                {
                    i=i+2;
                    j=j+1;
                    step++;
                }
                else if((grid[i][j]==grid[i-2][j-1]-1)&&(i-2>=0)&&(j-1>=0))
                {
                    i=i-2;
                    j=j-1;
                    step++;
                }
                else if((grid[i][j]==grid[i+2][j-1]-1)&&(j-1>=0)&&(i+2<grid_size))
                {
                    i=i+2;
                    j=j-2;
                    step++;
                }
                else if((grid[i][j]==grid[i-2][j+1]-1)&&(i-2>=0)&&(j+1<grid_size))
                {
                    i=i-2;
                    j=j+1;
                    step++;

                }
                else
                    break;
            }
            if((grid[i][j]==grid_size*grid_size)&&(step==grid_size*grid_size))
                    return true;
        }
    return false;
    }
};
#if 0
int main()
{
    
    string s("Hello World!!!!");
    for(auto &c : s)
        c = toupper(c);
    cout << s << endl;
    decltype(s.size()) punct_cnt=0;
    for(auto c : s)
        if(ispunct(c))
            ++punct_cnt;
    cout << punct_cnt <<" punctuation characters in " <<s<< endl;
    
    string s("Hello World!!!!");
    //依次处理s中的字符直至我们处理完全部字符或者遇到一个空白
    for (decltype(s.size()) index =0;index != s.size () && !isspace(s[index]); ++index)
            s [index] = toupper(s [index]);//将当前字符改成大写形式
    cout << s << endl;
    
    
}

#endif
int main(){
while (cin >> item1 >> item2) {
    try {
        //执行添加两个sales_item对象的代码
        //如果添加失败，代码抛出一个runtime_error异常
    } catch (runtime_error err){
        //提醒用户两个工SBN必须一致，询问是否重新输入
        cout << err.what ()
            << " \nTry Again? Enter y or n" << endl;char c;
        cin >>c;

    }
        if( !cin ll c == 'n')
        break; //跳出 while循环
        }
    }




