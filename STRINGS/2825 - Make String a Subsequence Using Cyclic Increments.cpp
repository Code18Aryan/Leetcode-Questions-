#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        int i = 0, j = 0;

        while( i < n && j < m){
             
             if(str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] - 25 == str2[j]) j++;

             i++;
        }

        return j == m;
        
    }
};

int main() {
    
    Solution leetcode;
	
	string  str1 = "abc", str2 = "ad";
	
	
	cout<<leetcode.canMakeSubsequence(str1,str2);
	
	

}
