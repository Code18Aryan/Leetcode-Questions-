#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {

        int n = s.size();

        if(n < 3) return s;

        string ans = "";

        ans += s[0];
        ans += s[1];

        for(int i=2; i<n; i++){
             
              if(s[i] == s[i-1] && s[i] == s[i-2]) continue;

              else ans += s[i];
        }

        return ans;
        
    }
};



int main(){
     
     string  s = "leeetcode";
     string s2 = "aaabaaaa";
     
     Solution leetcode;
     
    cout<<leetcode.makeFancyString(s)<<endl;
    cout<<leetcode.makeFancyString(s2);
}