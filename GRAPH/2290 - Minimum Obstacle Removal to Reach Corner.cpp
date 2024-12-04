#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    #define p pair<int,pair<int,int>> 

    bool isValid(int row , int col , int m , int n){
         
          if(row >=0 && row < m && col >= 0 && col < n) return true;

          return false;
    }

    int minimumObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue< p , vector<p> , greater<p> > pq;
        pq.push({0,{0,0}});

        vector<vector<int>> distance(m , vector<int>(n,1e9));
        distance[0][0] = 1e9;

        vector<int> changeRow = {-1,0,+1,0};
        vector<int> changeCol = {0,+1,0,-1};

        while(!pq.empty()){
             
              auto x = pq.top();
              pq.pop();

              int dist = x.first;
              int row = x.second.first;
              int col = x.second.second;

              for(int i=0; i<4; i++){
                 
                  int nRow = row + changeRow[i];
                  int nCol = col + changeCol[i];

                  if(isValid(nRow,nCol,m,n)){
                     
                      if(grid[nRow][nCol] == 1){
                         
                          if(dist + 1 < distance[nRow][nCol]){
                             
                              distance[nRow][nCol] = dist + 1;

                              pq.push({distance[nRow][nCol],{nRow,nCol}});
                          }
                          
                      }

                      else{
                         
                          if(dist < distance[nRow][nCol]){
                             
                              distance[nRow][nCol] = dist;

                              pq.push({distance[nRow][nCol],{nRow,nCol}});
                          }
                      }
                  }
              }
        }

        return distance[m-1][n-1];

        
    }
};

int main() {

  Solution leetcode;
  
 vector<vector<int>> grid = {{0,1,1},{1,1,0},{1,1,0}};
  
 vector<vector<int>> grid2 = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
 
 cout<<leetcode.minimumObstacles(grid)<<endl;
 
  cout<<leetcode.minimumObstacles(grid2)<<endl;
  
  

}
