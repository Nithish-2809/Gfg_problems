class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        queue<pair<int,int>>q;
        vector<int>visited(V,0);
        
        q.push({src,0});
        visited[src] = 1;
        
        while(!q.empty()) {
            int val = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(val==dest) return dist;
            
            for(auto it : adj[val]) {
                if(!visited[it]) {
                    q.push({it,dist+1});
                    visited[it] = 1;
                }
            }
        }
        
    return -1;
    }
};
