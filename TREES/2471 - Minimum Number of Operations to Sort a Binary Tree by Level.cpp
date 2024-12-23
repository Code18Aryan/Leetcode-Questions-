#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:

    int findIndex(vector<int>&nums ,int target){
         
          int n = nums.size();

          int low = 0;
          int high = n-1;

          while( low <= high){
             
              int mid = (low + high)/2;

              if(nums[mid] == target) return mid;

              else if(nums[mid] < target) low = mid+1;

              else high = mid-1;
          }

          return -1;
    }
    
    int findOperation(vector<int>&nums){
         
          vector<int> sortedArray(nums.begin(),nums.end());

          int swaps = 0;

          sort(sortedArray.begin(),sortedArray.end());

          unordered_map<int,int> mpp;

          for(int i=0; i<nums.size(); i++){
            
             mpp[nums[i]] = i;
              
          }

          for(int i=0; i<nums.size(); i++){
             
              if(nums[i] == sortedArray[i]) continue;

              int index = mpp[sortedArray[i]];

              mpp[nums[i]] = index;

            //  mpp[sortedArray[i]] = i;

              swap(nums[i],nums[index]);
              
              swaps++;

          }

          return swaps;
    }

public:
    int minimumOperations(TreeNode* root) {

        if(root == NULL) return 0;

        TreeNode* tempRoot = root;

        queue<TreeNode*> q;
        q.push(tempRoot);

        int cnt = 0;

        while(!q.empty()){

             int size = q.size();
             vector<int> ans;

             while(size--){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  if(node -> left) q.push(node -> left);
                  if(node -> right) q.push(node -> right);

                  ans.push_back(node -> val);
             }

             cnt += findOperation(ans);
        }

        return cnt;
        
    }
};

int main() {
	// your code goes here

}
