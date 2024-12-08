#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[100001][3];
    int n;

    int bs(vector<vector<int>> &matrix, int endTime){
         
         int low = 0;
         int high = n-1;
         int result = n;

         while( low <= high){
             
              int mid = low + (high - low) / 2;

              if(matrix[mid][0] > endTime){
                 
                  result = mid;
                  
                  high = mid-1;
              }

              else low = mid + 1;
         }

         return result;
    }

    int solve(vector<vector<int>> & events , int i , int cnt){
         
         if(cnt ==2 || i >= n){
             
              return 0;
         }

         if(t[i][cnt] != -1) return t[i][cnt];

         int nextValidEventIndex = bs(events, events[i][1]);

         int take = events[i][2] + solve(events,nextValidEventIndex,cnt +1);

         int notTake = solve(events,i+1,cnt);

         return t[i][cnt] = max(take , notTake);
    }


    int maxTwoEvents(vector<vector<int>>& events) {
        
        n = events.size();

        sort(begin(events),end(events));

        memset(t,-1,sizeof(t));

        int cnt = 0;

        return solve(events,0,cnt);
    }
};

int main() {
	// your code goes here

}
