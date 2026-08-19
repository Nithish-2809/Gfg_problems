void dfs(int node,stack<int>&st,vector<int>&visited,const vector<vector<int>>&adj) {
    visited[node] = 1;
    
    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfs(it,st,visited,adj);
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
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int>visited(V,0);
        
        stack<int>st;
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfs(i,st,visited,adj);
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