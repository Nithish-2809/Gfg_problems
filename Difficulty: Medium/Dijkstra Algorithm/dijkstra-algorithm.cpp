class Solution {
  public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

          vector<vector<pair<int,int>>> adj(V);

          for(auto edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int wt = edge[2];

              adj[u].push_back({v, wt});
              adj[v].push_back({u, wt});
          }

          vector<int> dist(V, INT_MAX);

          set<pair<int,int>> st;

          st.insert({0, src});
          dist[src] = 0;

          while(!st.empty()) {

              auto it = *st.begin();

              int currDist = it.first;
              int node = it.second;

              st.erase(it);

              for(auto edge : adj[node]) {

                  int nextNode = edge.first;
                  int wt = edge.second;

                  if(currDist + wt < dist[nextNode]) {

                      // Remove old distance
                      if(dist[nextNode] != INT_MAX)
                          st.erase({dist[nextNode], nextNode});

                      dist[nextNode] = currDist + wt;

                      st.insert({dist[nextNode], nextNode});
                  }
              }
          }

          return dist;
      }
  };