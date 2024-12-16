#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    #define p pair<int,int>

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        int n = nums.size();


        // Time complexity - O(n) for pushElement + O(n) for multiplication + O(n) for insert ~ O(3n);
        // Space Complexity - O(1) 

        vector<int> result(n);

        priority_queue<p , vector<p> , greater<p>> pq;

        for(int i=0; i<n; i++){
             
              pq.push({nums[i],i});
        }
        

        while(k--){
             
              int element = pq.top().first;
              int index = pq.top().second;

              pq.pop();

              int newElement = element * multiplier;

              pq.push({newElement , index});
        }

        while(!pq.empty()){
             
              auto x = pq.top();
              pq.pop();

              int element = x.first;
              int index = x.second;

              result[index] = element;
        }

        return result;
        
    }
};

int main() {


  Solution leetcode;
  
 vector<int>  nums = {2,1,3,5,6};
 int  k = 5, multiplier = 2;
 
 vector<int>  nums2 = {1,2};
 int  k2 = 3, multiplier2 = 4;
 
 vector<int> ans1 = leetcode.getFinalState(nums, k, multiplier);
 
 vector<int> ans2 = leetcode.getFinalState(nums2, k2, multiplier2);
 
 for(auto x : ans1) cout<<x<<" ";
 
 cout<<endl;
 
 for(auto x : ans2) cout<<x<<" ";
 
 cout<<endl;

}
