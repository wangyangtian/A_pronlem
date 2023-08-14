#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for (it=nums.begin();it!=nums.end();)
        {
            if(*it==val)
                it = nums.erase(it);
            else
                it++;
        }
        return nums.size();
    }
};

int main(){
    vector<int> nums={1,5,3,3,4,7};
    Solution solution;
    solution.removeElement(nums,3);
    for(int i:nums)
        cout<<i <<" ";
    return 0;
}