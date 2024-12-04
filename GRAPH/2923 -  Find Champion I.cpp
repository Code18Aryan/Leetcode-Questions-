#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> adj[n];

        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){
             
              for(int j=0; j<n; j++){

                  if( i != j){
                     
                      if(grid[i][j] == 1){
                         
                          indegree[j]++;
                      }

                      else indegree[i]++;
                  }
              }
        }

        for(int i=0; i<n; i++){
             
              if(indegree[i] == 0) return i;
        }

        return -1;
        
    }
};

int main() {
	
	Solution leetcode;
	
	vector<vector<int>> grid = {{0,1},{0,0}};
	
	vector<vector<int>> grid2 = {{0,0,1},{1,0,1},{0,0,0}};
	
	cout<<leetcode.findChampion(grid)<<endl;
	cout<<leetcode.findChampion(grid2)<<endl;

}
