#include<bits/stdc++.h>
using namespace std;

  class Solution {
   public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();

        if( n < 3) return false;

        for(int i=0; i<n-2; i++){
             
             if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1) return true;
        }
        
        return false;
    }
};


int main(){

     vector<int> nums = {2,6,4,1};
     vector<int> nums2 = {1,2,34,3,4,5,7,23,12};

    Solution leetcode;

    cout<<leetcode.threeConsecutiveOdds(nums)<<endl;
    cout<<leetcode.threeConsecutiveOdds(nums2);


     
      
}