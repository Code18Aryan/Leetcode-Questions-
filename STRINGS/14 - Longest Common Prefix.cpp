#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string smallest = "";
        int n = strs.size();

        int size = INT_MAX;

        string ans = "";

        for(int i=0; i<n; i++){
             
              if(strs[i].size() < size){
                 
                  size = strs[i].size();
                  smallest = strs[i];
              }
        }

        for(int i=0; i<size; i++){
             
              char ch = smallest[i];

              bool check = true;

              for(int j=0; j<n; j++){

                string temp = strs[j];
                 
                 if(temp[i] != ch){
                     
                    check = false;
                    break;  
                 }

              }

              if(check == false) break;

              ans += ch;

        }

        return ans;
        
    }
};

int main(){
     
    vector<string > nums1 = {"flower","flow","flight"};
    vector<string> nums2 = {"dog","racecar","car"};
    
    
    Solution leetcode;
    
    
    cout<<leetcode.longestCommonPrefix(nums1)<<endl;
    cout<<leetcode.longestCommonPrefix(nums2);
}