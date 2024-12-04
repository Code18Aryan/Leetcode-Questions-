#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:

    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        int i = 0,j = 0;

        while( i < n && j < m){
             
             if(s[i] == t[j]) i++;

             j++;
        }

        return i == n;
        
    }
};

int main() {


 Solution leetcode;

 string s = "abc", t = "ahbgdc";
 
 cout<<leetcode.isSubsequence(s,t);
   

}
