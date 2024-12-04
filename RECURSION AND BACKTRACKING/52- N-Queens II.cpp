#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValidPlace(int row, int col , int n, vector<string>&board){
         
         int sr = row;
         int sc = col;

         for(int i=row-1; i>=0; i--){
             
              if(board[i][col] == 'Q') return false;

         }

         row = sr-1;
         col = sc+1;

         while( row >=0 && col < n){
             
             if(board[row--][col++] == 'Q') return false;
         }

         row = sr-1;
         col = sc-1;

         while(row >= 0 && col >= 0){

             if(board[row--][col--] == 'Q') return false;
         }

         return true;
    }

    void placeQueen(int row , int n , vector<string>&board, int &ans){
         
         if(row >= n){
             
             ans += 1;
             return;
         }

         for(int col=0; col<n; col++){
             
             if(isValidPlace(row,col,n,board)){
                 
                  board[row][col] = 'Q';

                  placeQueen(row+1,n,board,ans);

                  board[row][col] = '.';
             }
         }
    }

    int totalNQueens(int n) {

        vector<string> board(n , string(n,'.'));
        
        int ans = 0;

        placeQueen(0,n,board,ans);

        return ans;

        
    }
};

int main() {
    
    Solution leetcode;
    
    for(int i=1; i<=9; i++){
         
          cout<<leetcode.totalNQueens(i)<<endl;
    }
	
	

}
