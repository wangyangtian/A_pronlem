#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i != n; ++i) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
int main(){
    vector<int> nums1={1,5,3,0,0,0}, nums2={6,8,2};
    int m=3,n=3;
    Solution solution;
    solution.merge(nums1,m,nums2,n);
    for(int i:nums1)
        cout<<i <<" ";
    return 0;
}