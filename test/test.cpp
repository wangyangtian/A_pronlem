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

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>> vv;
    vv.push_back({1});
    vv.push_back({1,1,1});
    vv.push_back({1,1,1});
    vector<vector<int>>::iterator it=vv.end();
    vector<int>::iterator it1=it->end();
    cout<<distance(vv.begin(),it);
    

    return 0;
}