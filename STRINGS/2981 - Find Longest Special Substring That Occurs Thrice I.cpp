#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkValid(string s){
         
         char ch = s[0];

         for(auto x : s){
             
             if(x != ch) return false;
         }

         return true;
    }

    int maximumLength(string s) {

        int n = s.size();

        unordered_map<string,int> mpp;

        int maxLength = -1;

        vector<string> temp;

        for(int i=0; i<n; i++){
             
              string str = "";

              for(int j=i; j<n; j++){
                 
                   str.push_back(s[j]);

                   mpp[str]++;
              }
        }

        for(auto x : mpp){
             
             if(x.second >= 3){
                 
                  temp.push_back(x.first);
             }
        }

        for(int i=0; i<temp.size(); i++){
             
              if(checkValid(temp[i])){
                 
                   int size = temp[i].size();

                  maxLength = max(maxLength, size);
       
              }
        }

        return maxLength;
        
    }
};

int main() {
	
	Solution leetcode;
	
	string s1 = "aaaa", s2 = "abcdef", s3 = "abcaba";
	
	cout<<leetcode.maximumLength(s1)<<endl;
	cout<<leetcode.maximumLength(s2)<<endl;
	cout<<leetcode.maximumLength(s3)<<endl;

}
