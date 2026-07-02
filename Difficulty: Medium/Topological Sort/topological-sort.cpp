void dfs(const vector<vector<int>>&adj,vector<int>&visited,int node,stack<int>&st) {
    visited[node] = 1;
    
    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfs(adj,visited,it,st);
        }
    }
    st.push(node);
}






class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto it : edges) {
            int v = it[0];
            int u = it[1];
            
            adj[v].push_back(u);
    }
        
        stack<int>st;
        
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfs(adj,visited,i,st);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
    return ans;
    }
};