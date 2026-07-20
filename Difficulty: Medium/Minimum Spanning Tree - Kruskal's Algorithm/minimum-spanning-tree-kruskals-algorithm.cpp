class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUltimateParent(u);
        int ultp_v = findUltimateParent(v);

        if (ultp_u == ultp_v) {
            return;
        }

        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int mstWt = 0;
        DisjointSet ds(V);
        
          sort(edges.begin(), edges.end(),
            [](vector<int> &a, vector<int> &b) {
                return a[2] < b[2];
            });
        
        for(auto it : edges) {
            int u =  it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)) {
                mstWt += wt;
                ds.unionByRank(u,v);
            }
        }
        
    return mstWt;
    }
};