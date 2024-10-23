#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  
 
class Solution {

private:

   unordered_map<int,int> findLevelSum(TreeNode* root){
         
         unordered_map<int,int> mpp;

         int level = 0;

         queue<TreeNode*> q;
         q.push(root);

         while(!q.empty()){
             
              int size = q.size();
              int sum = 0;

              for(int i=0; i<size; i++){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  sum += node -> val;

                  if(node -> left) q.push(node -> left);
                  if(node -> right) q.push(node -> right);


              }

              mpp[level] = sum;
              level += 1;
         }

         return mpp;
    }

    void replaceValues(TreeNode* &root ,  unordered_map<int,int> mpp){
         
          root -> val = 0;

          queue<TreeNode*> q;
          q.push(root);

          int level = 1;

          while(!q.empty()){
             
              int size = q.size();

              for(int i=0; i<size; i++){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  int sublingSum = 0;

           
                  if(node->left) sublingSum += node->left->val;
                  if(node->right) sublingSum += node->right->val;

           
                  if(node->left) {

                    node->left->val = mpp[level] - sublingSum;
                    q.push(node->left);
                   }

            
                    if (node->right) {
                    node->right->val = mpp[level] - sublingSum;
                    q.push(node->right);
                 }

              }

              level += 1;
          }
          
    }



public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(root == NULL) return root;

        unordered_map<int,int> mpp = findLevelSum(root);

        replaceValues(root ,mpp);

        return root;
        
    }
    
    void dfs(TreeNode*root){
         
         if(root == NULL) return;
         
         cout<<root -> val<<endl;
         
         dfs(root -> left);
         dfs(root -> right);
    }
};






int main(){
     
    Solution leetcode;
    
    TreeNode* root = new TreeNode(5);
    
    root -> left = new TreeNode(4);
    root -> right = new TreeNode(9);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(10);
    root -> right -> right = new TreeNode(11);
    
    
    TreeNode* newRoot = leetcode.replaceValueInTree(root);
    
    leetcode.dfs(newRoot);
    
    
}












