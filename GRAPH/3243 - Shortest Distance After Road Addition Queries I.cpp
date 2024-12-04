#include <bits/stdc++.h>
using namespace std;

class Solution {

    #define p pair<int,int>

private:

    int dikstraAlgo(int src , int n , vector<int>adj[]){

        vector<int> distance(n,1e9);
        distance[src] = 0;

        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,src});

        while(!pq.empty()){
             
             int dist = pq.top().first;
             int node = pq.top().second;

             pq.pop();

             for(auto adjNode : adj[node]){

                  if(dist + 1 < distance[adjNode]){
                     
                      distance[adjNode] = dist + 1;

                      pq.push({dist + 1, adjNode});
                  }
             }
        }

        return distance[n-1];

    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int> result;

        vector<int>adj[n];

        for(int i=0; i<n-1; i++){
             
              int u = i;
              int v = i+1;

              adj[u].push_back(v);
        }

        for(auto x : queries){
             
             int u = x[0];
             int v = x[1];

             adj[u].push_back(v);

             int dist = dikstraAlgo(0,n,adj);

             result.push_back(dist);
        }

        return result;
        
    }
};

int main() {

  Solution leetcode;
  
  int n = 5;
  vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
  
  int  n2 = 4;
  vector<vector<int>> queries2 = {{0,3},{0,2}};
  
  
  vector<int> ans1 = leetcode.shortestDistanceAfterQueries(n,queries);
  vector<int> ans2 = leetcode.shortestDistanceAfterQueries(n2,queries2);
  
  for(auto x : ans1) cout<<x<<" ";
  
  cout<<endl;
  
  for(auto x : ans2) cout<<x<<" ";
  
  
  

}
