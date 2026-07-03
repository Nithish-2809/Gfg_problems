class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark all characters that are present
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // Invalid case: longer word before its prefix
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Compute indegrees
        for (int u = 0; u < 26; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        // Push all present characters having indegree 0
        int totalChars = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalChars++;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Cycle exists
        if (ans.size() != totalChars)
            return "";

        return ans;
    }
};