#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int cnt = 0;
        int sum = 0;

        unordered_set<int>st(banned.begin(),banned.end());

        for(int i=1; i<=n; i++){
             
              if(st.find(i) == st.end() && sum + i <= maxSum){
                 
                  sum += i;
                  cnt++;
              }
        }

        return cnt;
        
    }
};

int main() {
	
	
	Solution leetcode;
	
	vector<int> banned = {1,6,5};
	
	int n = 5, maxSum = 6;
	
	cout<<leetcode.maxCount(banned,n,maxSum);

}
