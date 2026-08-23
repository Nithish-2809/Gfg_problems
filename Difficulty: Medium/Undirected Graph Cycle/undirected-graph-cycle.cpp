class Solution {
  public:
      bool isCycle(int V, vector<vector<int>>& edges) {
          vector<vector<int>> adj(V);

          for(auto it : edges) {
              int u = it[0];
              int v = it[1];

              adj[u].push_back(v);
              adj[v].push_back(u);
          }

          queue<pair<int,int>> q;   // {node, parent}
          vector<int> visited(V, 0);

          for(int i = 0; i < V; i++) {

              if(visited[i]) continue;

              q.push({i, -1});
              visited[i] = 1;

              while(!q.empty()) {
                  int node = q.front().first;
                  int parent = q.front().second;
                  q.pop();

                  for(auto it : adj[node]) {

                      if(!visited[it]) {
                          visited[it] = 1;
                          q.push({it, node});
                      }
                      else if(it != parent) {
                          return true;
                      }
                  }
              }
          }

          return false;
      }
  };