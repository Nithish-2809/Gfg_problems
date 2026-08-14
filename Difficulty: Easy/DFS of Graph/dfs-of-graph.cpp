void dfsTraversal(vector<vector<int>>&adj,vector<int>&ans,int node,vector<int>&visited) {
    visited[node] = 1;
    ans.push_back(node);
    
    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfsTraversal(adj,ans,it,visited);
        }
    }
}







class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n = adj.size();
        
        vector<int>visited(n,0);
        
        dfsTraversal(adj,ans,0,visited);
        
    return ans;
    }
};