
  
  #include<bits/stdc++.h>
  using namespace std;


  class TreeNode{
     
     public:

     int val;
     TreeNode* left;
     TreeNode* right;

     TreeNode( int val){
         
         this -> val = val;
         this -> left = NULL;
         this -> right = NULL;
     }
  };



    class Solution {

    public:

    vector<vector<int>> bfs(TreeNode* root){
         
         vector<vector<int>> ans;

         if( root == NULL) return ans;

         queue<TreeNode*> q;
         q.push(root);

         while( !q.empty()){
             
              int size = q.size();
              vector<int>level;

              for(int i=0; i<size; i++){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  if( node -> left != NULL) q.push(node -> left);
                  if( node -> right != NULL) q.push(node -> right);

                  level.push_back(node -> val);
              }

              ans.push_back(level);
         }

         return ans;
    }


    void print(vector<int>&nums){
         
          for(auto x : nums){
             
              cout<<x<<" ";
          }

          cout<<endl;
    }

    void inorder(TreeNode* root , vector<int>&nums){
         
         if( root == nullptr) return;


         inorder(root -> left , nums);
         nums.push_back(root ->val);
         inorder(root -> right ,nums);
    }


    TreeNode* createTree(vector<int>&nums ,int low , int high){
         
          if( low > high) return NULL;

          int mid = (low + high)/2;

          TreeNode* root = new TreeNode(nums[mid]);

          root -> left = createTree(nums , low , mid-1);

          root -> right = createTree(nums,mid+1,high);

          return root;
    }


    TreeNode* balanceBST(TreeNode* root) {

        vector<int>nums;

        inorder(root,nums);

        TreeNode* balancedBST = createTree(nums,0,nums.size()-1);

        return balancedBST;
        
    }
};




   int main(){
     
      TreeNode* root = new TreeNode(1);
      root -> right = new TreeNode(2);
      root -> right -> right = new TreeNode(3);
      root -> right -> right -> right = new TreeNode(4);   


      Solution leetcode;

      TreeNode* ansRoot = leetcode.balanceBST(root);

      vector<vector<int>> levelOrder = leetcode.bfs(ansRoot);

      for(auto x : levelOrder){
         
          leetcode.print(x);

      }





   }