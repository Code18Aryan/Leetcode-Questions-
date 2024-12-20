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

    deque<vector<int>> getLevels(TreeNode* root){

         deque<vector<int>> dq;

         queue<TreeNode*> q;
         q.push(root);

         int level = 0;

         while(!q.empty()){
             
              int size = q.size();
              vector<int> nodes;

              while(size--){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  if(node -> right) q.push(node -> right);
                  if(node -> left) q.push(node -> left);

                  nodes.push_back(node -> val);
              }

              if(level % 2 == 1){
                
                 dq.push_back(nodes);
              }

              level ++;
         }

         return dq;

    }


    void reverseLevels(TreeNode* L , TreeNode* R , int level){
         
         if(L == NULL || R == NULL) return;

         if(level % 2 == 1){

             swap(L -> val , R -> val);
         }

         reverseLevels(L -> left , R -> right , level + 1);
         reverseLevels(L -> right, R -> left , level + 1);

    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        /*

        I will use three appraoch to solve this question 

    //  1st using deque of vectors to store odd level nodes in reverse fashion using bfs then 
        again bfs to solve the element

    //   2nd using single bfs using queue and vector

    //   3rd using general dfs technique 

    */


               // 1st Approach

        

      
      /*  deque<vector<int>> dq = getLevels(root);

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
             
             int size = q.size();

             vector<int> nums;

             int index = 0;

             if(level % 2 == 1){
                 
                  nums = dq.front();
                  dq.pop_front();
             }

             while(size--){
                 
                  TreeNode* node = q.front();
                  q.pop();

                  if(node -> left) q.push(node -> left);
                  if(node -> right) q.push(node -> right);

                  if(level % 2 == 1){
                     
                      node -> val = nums[index++];
                  }
             }

             level ++;
        }

        return root;   */


           // 2nd Approach Using simple BFS


       /*  queue<TreeNode*> q;
        q.push(root);

         int level = 0;

         while(!q.empty()){
             
              int size = q.size();

              vector<TreeNode*> nodes;

              while(size--){
                 
                  TreeNode* node = q.front();
                  q.pop();


                  if(node -> left) q.push(node -> left);
                  if(node -> right) q.push(node -> right);
                  
                  nodes.push_back(node);
              }

              if(level % 2 == 1){
                
                  int i = 0, j = nodes.size()-1;

                  while( i < j){
                     
                      int temp = nodes[i] -> val;
                      nodes[i] -> val = nodes[j] -> val;
                      nodes[j] -> val = temp;

                      i++;  j--;
                  }

              }

              level ++;
         }

        return root;   */


        if(root == NULL) return root;

        reverseLevels(root -> left , root -> right, 1);

        return root;
        
    }
};

int main() {
	// your code goes here

}
