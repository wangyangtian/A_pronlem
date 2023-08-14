#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    for(int i=0; i<nums.size()-2;){
        if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            nums.erase(nums.begin()+(i+2));
        }
        else
            i++;
    }
    for(int c:nums)
        cout<<c<<" ";
    return 0;
}