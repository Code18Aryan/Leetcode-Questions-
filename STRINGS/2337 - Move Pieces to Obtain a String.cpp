#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {

        int n = start.size();
        int m = target.size();

        int i = 0, j = 0;

        while( i < n || j < m){
             
             while(start[i] == '_' && i < n) i++;

             while(target[j] == '_' && j < m) j++;

             if( i == n || j == m){
                 
                  return i == n && j == m;
             }

             if(start[i] != target[j]) return false;

             if(start[i] == 'L' && i < j) return false;
             if(start[i] == 'R' && i > j) return false;

             i++; j++;
        }
        
        return true;
    }
};

int main() {

  Solution leetcode;
  
   string start = "_L__R__R_", target = "L______RR";
   
   cout<<leetcode.canChange(start,target);

}
