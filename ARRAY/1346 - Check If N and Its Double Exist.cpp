#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        int n = arr.size();

        if( n < 2) return false;

        unordered_map<int,int > mpp;

        for(int i=0; i<n; i++){

            mpp[arr[i]] = i;
        }

        for(int i=0; i<n; i++){

            if(mpp.find(arr[i] * 2) != mpp.end()){
                 
                 if(mpp[arr[i] * 2] != i) return true;
            }
        }

        return false;
    }
};

int main() {

   Solution leetcode;
   
   vector<int> arr = {10,2,5,3};
    vector<int> arr2 = {3,1,7,11};

   cout<<leetcode.checkIfExist(arr)<<endl;
   cout<<leetcode.checkIfExist(arr2);
}
