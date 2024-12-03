#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_set<int>cols,diaRight,diaLeft;

    bool isValidPlace(int row, int col,int n, vector<string>&board){
         
          int dr = row;
          int dc = col;

          for(int i=row-1; i>=0; i--){
              
              if(board[i][col] == 'Q') return false;
          }

          row = dr-1;
          col = dc+1;

          while(row >= 0 && col < n){
             
             if(board[row--][col++] == 'Q') return false;
          }

          row = dr-1;
          col = dc-1;

          while( row >= 0 && col >= 0){
             
              if(board[row--][col--] == 'Q') return false;
          }

          return true;
    }

    void placeQueen(int row , int n , vector<vector<string>>&ans , vector<string> &board){
         
          if(row >= n){
             
               ans.push_back(board);
               return;
          }

          for(int col=0; col<n; col++){

               int diagonalRight = row + col;
               int diagonalLeft = row-col;

               if(cols.find(col) != cols.end() || diaLeft.find(diagonalLeft) != cols.end() || diaRight.find(diagonalRight) != diaRight.end()) continue;

               cols.insert(col);
               diaRight.insert(diagonalRight);
               diaLeft.insert(diagonalLeft);

               board[row][col] = 'Q';

               placeQueen(row+1,n,ans,board);

               cols.erase(col);
               diaRight.erase(diagonalRight);
               diaLeft.erase(diagonalLeft);

               board[row][col] = '.';
 
            //   if(isValidPlace(row,col,n,board)){
                 
            //       board[row][col] = 'Q';

            //       placeQueen(row+1,n,ans,board);

            //       board[row][col] = '.';
            //   }


          }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n,'.'));

        placeQueen(0,n,ans,board);

        return ans;
        
    }
};


int main(){


    Solution leetcode;

    vector<vector<string>> ans = leetcode.solveNQueens(4);

    for(auto x : ans){
         
          for(auto y : x){

              cout<<y;
              cout<<endl;
          }

          cout<<endl;
    }
     

}