#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxIndex = 0;

        for(int i=0; i<nums.size(); i++){
             
              if(i > maxIndex) return false;

              maxIndex = max(maxIndex , nums[i] + i);
        }

        return true;
        
    }
};


int main(){
    
    vector<int> nums = {2,3,1,1,4};
    vector<int> nums2= {3,2,1,0,4};
    
    Solution leetcode;
    
    
    cout<<leetcode.canJump(nums)<<endl;
    cout<<leetcode.canJump(nums2);
}