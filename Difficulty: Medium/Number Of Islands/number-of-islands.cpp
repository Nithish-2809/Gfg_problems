class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DisjointSet ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;

        int cnt = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto &op : operators) {

            int row = op[0];
            int col = op[1];

            if (vis[row][col]) {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            int node = row * m + col;

            for (int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]) {

                    int adjNode = nr * m + nc;

                    if (ds.findUltimateParent(node) != ds.findUltimateParent(adjNode)) {
                        ds.unionBySize(node, adjNode);
                        cnt--;
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};