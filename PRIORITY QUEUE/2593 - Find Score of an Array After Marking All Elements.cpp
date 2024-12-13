#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define ll long long
    #define p pair<int,int>

    long long findScore(vector<int>& nums) {

        ll sum = 0;

        priority_queue< p , vector<p> , greater<p> > pq;

        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++){
             
             pq.push({nums[i],i});
        }

        while(!pq.empty()){
             
              int element = pq.top().first;
              int index = pq.top().second;

              pq.pop();

              if(st.find(index) == st.end()){
                 
                   sum += element;

                   st.insert(index);

                   if(index > 0 && index < nums.size()-1){
                     
                      st.insert(index -1);
                      st.insert(index +1);
                   }

                   else if(index == 0) st.insert(index + 1);

                   else st.insert(index -1);
              }
        }

        return sum;
        
    }
};

int main() {
    
    Solution leetcode;

 vector<int>  nums = {2,1,3,4,5,2};
 vector<int>  nums2 = {2,3,5,1,3,2};
 
 cout<<leetcode.findScore(nums)<<endl;
 cout<<leetcode.findScore(nums2);
 


}
