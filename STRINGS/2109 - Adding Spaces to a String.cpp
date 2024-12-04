#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void makeString(string & s , string& ans , int low , int high){
         
          for(int i=low; i<high; i++){
             
              ans.push_back(s[i]);
          }

          ans.push_back(' ');
    }

    string addSpaces(string s, vector<int>& spaces) {

        int n = spaces.size();

        string ans = "";

        makeString(s,ans,0,spaces[0]);

        for(int i=0; i<n-1; i++){
             
             int low = spaces[i];
             int high = spaces[i+1];

             makeString(s,ans,low,high);
        }

        makeString(s,ans,spaces[n-1],s.size());

        ans.pop_back();

        return ans;
        
    }
};

int main() {
	
    string s = "LeetcodeHelpsMeLearn";
	vector<int> spaces = {8,13,15};
	
	Solution leetcode;
	
	cout<<leetcode.addSpaces(s,spaces);

}
