void dfsTraversal(int start,
                  const vector<vector<int>>& adj,
                  vector<int>& visited,
                  vector<int>& ans) {
    
    visited[start] = 1;
    ans.push_back(start);
    
    for(auto it : adj[start]) {
        if(!visited[it]) {
            dfsTraversal(it,adj,visited,ans);
        }
    }
}


class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        
        vector<int>visited(n,0);
        vector<int>ans;
        
        
        dfsTraversal(0,adj,visited,ans);
        
    return ans;
        
    }
};