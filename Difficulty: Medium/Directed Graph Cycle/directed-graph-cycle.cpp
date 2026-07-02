bool dfs(const vector<vector<int>>& adj,
         int node,
         vector<bool>& visited,
         vector<bool>& inRecursion) {

    visited[node] = true;
    inRecursion[node] = true;

    for (auto it : adj[node]) {

        if (!visited[it]) {

            if (dfs(adj, it, visited, inRecursion))
                return true;

        }
        else if (inRecursion[it]) {
            return true;
        }
    }

    inRecursion[node] = false;
    return false;
}




class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            int v = it[0];
            int u = it[1];
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V,false);
        
        vector<bool>inRecursion(V,false);
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(adj,i,visited,inRecursion)) {
                    return true;
                };
            }
        }
        
    return false;
    }
};