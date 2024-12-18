#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();

        vector<int> nsr;
        vector<int> ans(n);

        stack<int> st;

        for(int i=n-1; i>=0; i--){

             if(st.empty()) nsr.push_back(0);

             else if(!st.empty() && st.top() <= prices[i]) nsr.push_back(st.top());

             else{
                 
                  while(!st.empty() && st.top() > prices[i]){
                     
                      st.pop();
                  }

                  if(st.empty()) nsr.push_back(0);

                  else nsr.push_back(st.top());
             }

             st.push(prices[i]);
        }

        for(int i=0; i<n; i++){
             
              ans[i] = prices[i] - nsr[n-1-i];
        }
        
        return ans;
    }
};

int main() {
	
	Solution leetcode;
	
	vector<int> nums = {8,4,6,2,3};
	
	vector<int> ans = leetcode.finalPrices(nums);
	
	for(auto x : ans) cout<<x<<" ";

}
