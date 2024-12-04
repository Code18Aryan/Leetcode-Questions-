#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0; i<9; i++){

            unordered_set<char> st;
             
             for(int j=0; j<9; j++){
                 
                 if(board[i][j] == '.') continue;

                 if(st.find(board[i][j]) != st.end()) return false;

                 st.insert(board[i][j]);
             }
        }

        for(int i=0; i<9; i++){

            unordered_set<char> st;
             
             for(int j=0; j<9; j++){
                 
                 if(board[j][i] == '.') continue;

                 if(st.find(board[j][i]) != st.end()) return false;

                 st.insert(board[j][i]);
             }
        }


         for(int sr=0; sr<9; sr += 3){
             
             int er = sr+2;

             for(int sc=0; sc<9; sc += 3){
                 
                  int ec = sc + 2;

                  unordered_set<char> st;

                  for(int i=sr; i<=er; i++){

                      for(int j=sc; j<=ec; j++){
                         
                          if(board[i][j] == '.') continue;

                          if(st.find(board[i][j]) != st.end()) return false;

                          st.insert(board[i][j]);
                      }
                  }
             }
         }

         return true;
        
    }
};


