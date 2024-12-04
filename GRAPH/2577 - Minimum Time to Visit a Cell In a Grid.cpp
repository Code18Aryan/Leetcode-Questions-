#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define p pair<int,pair<int,int>>

    int minimumTime(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] >  1 && grid[1][0] > 1) return -1;

        vector<vector<int>> minTime(m , vector<int>(n,1e9));
        vector<vector<int>> vis(m , vector<int>(n,0));
        
        minTime[0][0] = 0;

        priority_queue<p , vector<p>, greater<p>> pq;
        pq.push({0,{0,0}});

        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};

        while(!pq.empty()){
             
              auto x = pq.top();
              pq.pop();

              int time = x.first;
              int row = x.second.first;
              int col = x.second.second;

              if(row == m-1 && col == n-1) return minTime[m-1][n-1];

              if(vis[row][col]) continue;

              vis[row][col] = 1;

              for(int i=0; i<4; i++){
                 
                  int nRow = row + changeRow[i];
                  int nCol = col + changeCol[i];

                  if( nRow < 0 || nRow >= m || nCol >= n || nCol < 0 || vis[nRow][nCol]) continue;
                     
                      if(grid[nRow][nCol] <= time + 1){
                         
                          minTime[nRow][nCol] = time + 1;

                          pq.push({time + 1 , {nRow,nCol}});
                      }

                      else if( (grid[nRow][nCol] - time) % 2 == 0){
                         
                          minTime[nRow][nCol] = grid[nRow][nCol] + 1;

                          pq.push({grid[nRow][nCol] + 1, {nRow,nCol}});
                      }

                      else{
                         
                          minTime[nRow][nCol] = grid[nRow][nCol];

                          pq.push({grid[nRow][nCol], {nRow,nCol}});
                      }

                  
              }
              
        }

         return -1;
    }
};

int main() {
	
	
	Solution leetcode;

	
	vector<vector<int>> grid  = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
	
	vector<vector<int>> grid2 = {{0,2,4},{3,2,1},{1,0,4}};
	
	
	cout<<leetcode.minimumTime(grid)<<endl;
	cout<<leetcode.minimumTime(grid2)<<endl;	
	
	

}
