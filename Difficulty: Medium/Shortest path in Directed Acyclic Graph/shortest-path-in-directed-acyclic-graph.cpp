class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];

            adj[u].push_back({v, edgeWeight});
        }

        vector<int> dist(V, INT_MAX);
        set<pair<int,int>> st;

        dist[0] = 0;
        st.insert({0, 0});

        while (!st.empty()) {

            auto it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(st.begin());

            for (auto it : adj[node]) {

                int currNode = it.first;
                int edgeWeight = it.second;

                if (d + edgeWeight < dist[currNode]) {

                    if (dist[currNode] != INT_MAX)
                        st.erase({dist[currNode], currNode});

                    dist[currNode] = d + edgeWeight;
                    st.insert({dist[currNode], currNode});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};