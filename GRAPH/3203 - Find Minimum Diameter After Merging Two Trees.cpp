class Solution {
public:

    unordered_map<int,vector<int>> buildMap(vector<vector<int>>& edges){
         
         unordered_map<int,vector<int>> adj;

         for(auto x : edges){
             
              int u = x[0];
              int v = x[1];

              adj[u].push_back(v);
              adj[v].push_back(u);
         }

         return adj;
    }

    int findDiameter(unordered_map<int,vector<int>> &adj){
         
         pair<int,int> p1 = findMaxDistance(0,adj);
         pair<int,int> p2 = findMaxDistance(p1.first,adj);

         return p2.second;
    }

    pair<int,int> findMaxDistance(int src, unordered_map<int,vector<int>> &adj){
         
          int n = adj.size();

          unordered_map<int,bool> vis;
          vis[src] = 1;

          queue<int> q;
          q.push(src);

          int farthestNode = src;
          int distance = 0;

          while(!q.empty()){
             
              int size =  q.size();

              while(size--){
                 
                  int node = q.front();
                  q.pop();

                  farthestNode = node;

                  for(auto x : adj[node]){
                     
                      if(!vis[x]){
                         
                          vis[x] = 1;
                          q.push(x);
                      }
                  }
              }

              if(!q.empty()) distance++;
          }

          return {farthestNode,distance};
    }



    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        unordered_map<int,vector<int>> adj1 = buildMap(edges1);
        unordered_map<int,vector<int>> adj2 = buildMap(edges2);

        int dia1 = findDiameter(adj1);
        int dia2 = findDiameter(adj2);

        int minDia = (dia1 + 1)/2 + (dia2 + 1)/2 + 1;

        return max({dia1,dia2,minDia});

    }
};