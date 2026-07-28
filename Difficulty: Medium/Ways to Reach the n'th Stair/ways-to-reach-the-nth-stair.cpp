int countNumberOfStairs(int index,int n,vector<int>&dp) {
    if(index==n) return 1;
    if(index>n) return 0;
    
    if(dp[index]!=-1) return dp[index];
    
    int oneStep = countNumberOfStairs(index+1,n,dp);
    int twoSteps = countNumberOfStairs(index+2,n,dp);
    
    return dp[index] = oneStep+twoSteps;
}




class Solution {
  public:
    int countWays(int n) {
        
        vector<int>dp(n+1,-1);
        // code here
        return countNumberOfStairs(0,n,dp);
    }
};
