class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;

            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;

        while (parent[lastIndex] != lastIndex) {
            lis.push_back(arr[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        lis.push_back(arr[lastIndex]);

        reverse(lis.begin(), lis.end());

        return lis;
    }
};