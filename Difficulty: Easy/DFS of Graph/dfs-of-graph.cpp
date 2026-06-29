void dfsTraversal(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans) {
    
    visited[node] = 1;
    ans.push_back(node); 

    for (auto it : adj[node]) {  
        if (!visited[it]) {
            dfsTraversal(it, adj, visited, ans);
        }
    }
}

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> ans;

        dfsTraversal(0, adj, visited, ans);

        return ans;
    }
};