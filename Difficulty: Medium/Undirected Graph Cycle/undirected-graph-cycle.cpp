bool dfs(const vector<vector<int>>&graph,
        vector<int>&visited,
        int node,int parent) {
            
            visited[node] = 1;
            
            for(auto it : graph[node]) {
                if(!visited[it]) {
                    if(dfs(graph,visited,it,node)) return true;
                }
                else if(it!=parent) {
                    return true;
                }
            }
            
        return false;
        }



class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
        
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(adj,visited,i,-1)) {
                    return true;
                }
            }
        }
        
    return false;
    }
};