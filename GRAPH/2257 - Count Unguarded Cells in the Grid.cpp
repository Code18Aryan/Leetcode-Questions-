#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void markGuard(int row , int col , int m , int n , vector<vector<int>> &matrix){
         
          if( row < m-1){
             
              for(int down = row + 1; down < m; down++){
                 
                  if(matrix[down][col] == 2 || matrix[down][col] == 3) break;

                  matrix[down][col] = 1;
              }
          }

          if( row > 0){ 
             
               for(int up = row-1; up >= 0; up--){
                 
                  if(matrix[up][col] == 2 || matrix[up][col] == 3) break;

                  matrix[up][col] = 1;
               }
          }

          if(col < n-1){
             
              for(int right = col+1; right < n; right++){

                if(matrix[row][right] == 2 || matrix[row][right] == 3) break;
                 
                  matrix[row][right] = 1;
              }
          }

          if(col > 0){
             
              for(int left = col-1; left >= 0; left--){
                 
                  if(matrix[row][left] == 2 || matrix[row][left] == 3) break;

                  matrix[row][left] = 1;
              }
          }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

       vector<vector<int>> matrix(m , vector<int>(n,0));

       int cnt = 0;

       for(auto x : guards){
         
           int row = x[0];
           int col = x[1];

           matrix[row][col] = 2;
       }

       for(auto x : walls){
         
            int row = x[0];
            int col = x[1];

            matrix[row][col] = 3;
       }

       for(auto x : guards){
         
            int row = x[0];
            int col = x[1];

            markGuard(row,col ,m,n,matrix);
       }

       for(auto x : matrix){
         
           for(auto y : x){
             
               if(y == 0) cnt++;
           }
       }


       return cnt;
        
    }
};

int main() {


}
