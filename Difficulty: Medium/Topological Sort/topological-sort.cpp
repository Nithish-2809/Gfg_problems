
class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          vector<vector<int>>adj(V);

          vector<int>indegree(V);

          for(auto it : edges) {
              int u = it[0];
              int v = it[1];

              adj[u].push_back(v);
              indegree[v]++;
          }

          vector<int>ans;
          queue<int>q;

          for(int i=0;i<V;i++) {
              if(indegree[i]==0) {
                  q.push(i);
              }
          }

          while(!q.empty()) {
              int el = q.front();
              q.pop();
              ans.push_back(el);

              for(auto it : adj[el]) {
                  indegree[it]--;

                  if(indegree[it]==0) {
                      q.push(it);
                  }
              }
          }

          return ans;
      }
  };