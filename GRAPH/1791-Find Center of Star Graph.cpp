
  #include<bits/stdc++.h>
  using namespace std;


   class Solution {

     public:

    int findCenter(vector<vector<int>>& edges) {

       unordered_map<int,int> mpp;

       int m = edges.size();
       int n = edges[0].size();


       for(int i=0; i<m; i++){
         
           for(int j=0; j<n; j++){
             
                mpp[edges[i][j]]++;
           }
       }

       for(auto x : mpp){
         
           if(x.second > 1){
              
               return x.first;
           }
       }

       return -1;
        
    }
};



  int main(){
     
      vector<vector<int>> edges = { {1,2},{2,3},{4,2}};
      
      vector<vector<int>> edges2 = {{1,2},{5,1},{1,3},{1,4}};

      Solution leetcode;

      int centerEdge = leetcode.findCenter(edges);
      
      int centerEdge2 = leetcode.findCenter(edges2);

      cout<<centerEdge<<endl;
      cout<<centerEdge2<<endl;

     
  }