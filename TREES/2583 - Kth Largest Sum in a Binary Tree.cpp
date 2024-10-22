#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    
    public:
    
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
         
         this -> val = val;
         this -> left = NULL;
         this -> right = NULL;
    }
    
};

class Solution {
    
public:

    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long,vector<long long>, greater<long long>> pq;  // O(H)

        queue<TreeNode*> q; // O(N) N == number of nodes
        q.push(root);

        int height = 0;

        while(!q.empty()){
             
              int size =  q.size();

              long long sum = 0;

              for(int i=0; i<size; i++){
                 
                  TreeNode* node = q.front();
                  q.pop();     

                  if(node -> right) q.push(node -> right);
                  if(node -> left) q.push(node -> left);

                  sum += node -> val;
                  
              }

              height += 1;

              pq.push(sum);
 
              if(pq.size() > k) pq.pop();
        }

        if(height < k) return -1;

        return pq.top();
        
    }
};

int main() {
    
    Solution leetcode;
    
    TreeNode* root = new TreeNode(5);
    
    root -> left = new TreeNode(8);
    root -> right = new TreeNode(9);
    root -> left -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(1);
    root -> right -> left = new TreeNode(3);
    root -> right -> right = new TreeNode(7);
    root -> left -> left -> left = new TreeNode(4);
    root -> left -> left -> right = new TreeNode(6);
    
    long long ans = leetcode.kthLargestLevelSum(root,2);
    
    cout<<ans;
    


}
