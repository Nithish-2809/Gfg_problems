int calculateMaxPoints(vector<vector<int>>& mat, int index, int last, vector<vector<int>>& dp) {
    int n = mat.size();

    if(index == n-1) {
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, mat[index][i]);
            }
        }
        return maxi;
    }

    if(dp[index][last] != -1) return dp[index][last];

    int maxi = INT_MIN;

    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int points = mat[index][i] + calculateMaxPoints(mat, index + 1, i, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[index][last] = maxi;
}

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();

        // 4
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return calculateMaxPoints(mat, 0, 3, dp);
    }
};