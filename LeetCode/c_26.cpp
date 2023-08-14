#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
}
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4}; 
    cout<<solution.removeDuplicates(nums)<<endl;
    for(int c:nums)
        cout<<c<<" ";
    return 0;
}
