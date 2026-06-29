class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>visited(n+1,0);
        vector<int>ans;
        queue<int>q;
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]) {
                if(!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    
    return ans;
    }
};