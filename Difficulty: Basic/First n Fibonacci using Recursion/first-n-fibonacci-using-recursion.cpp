int fib(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

class Solution {
public:
    vector<int> fibonacciNumbers(int n) {
        vector<int> dp(n + 1, -1);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(fib(i, dp));
        }

        return ans;
    }
};