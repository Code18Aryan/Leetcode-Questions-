#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        // champion will be the node with no 0 indgree if two nodes are with indegree 0 then -1;

                // Appraoch first

        // vector<int> adj[n];

        // vector<int> indegree(n,0);

        // queue<int> q;

        // vector<int> ans;

        // for(auto x : edges){
             
        //      int u = x[0];
        //      int v = x[1];

        //      adj[u].push_back(v);

        // }

        // for(int i=0; i<n; i++){
             
        //       for(auto x :adj[i]){
                 
        //           indegree[x]++;
        //       }
        // }

        // int cnt = 0;

        // for(int i=0; i<n; i++){
             
        //       if(indegree[i] == 0){
                 
        //           q.push(i);
        //           cnt++;
        //       }

        //       if(cnt > 1) return -1;
        // }

        // return q.front();


               // Second Appraoch


        vector<int>indegree(n,0);

        int cnt = 0;
        int winner = -1;

        for(auto x : edges){

             indegree[x[1]]++;
        }

        for(int i=0; i<n; i++){
             
             if(indegree[i] == 0){
                 
                  cnt += 1;

                  winner = i;

                  if(cnt > 1) return -1;
             }
        } 

        return winner;

        
    }
};

int main() {

     Solution leetcode;
  

	
	vector<vector<int>> grid = {{0,1},{1,2}};
	
	vector<vector<int>> grid2 = {{0,2},{1,3},{1,2}};
	
	cout<<leetcode.findChampion(3,grid)<<endl;
	cout<<leetcode.findChampion(4,grid2)<<endl;

}
