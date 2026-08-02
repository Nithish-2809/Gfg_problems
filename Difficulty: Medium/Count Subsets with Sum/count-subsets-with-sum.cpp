int solve(vector<int>&nums,int index,int sum,vector<vector<int>>&dp) {
    int n = nums.size();
    if(index == n) {
        return (sum == 0);
    }
    
    if(dp[index][sum]!=-1) return dp[index][sum];
    
    int take = 0;
    if(nums[index]<=sum) {
        take = solve(nums,index+1,sum-nums[index],dp);
    }
    
    int notTake = solve(nums,index+1,sum,dp);
    
    return dp[index][sum] = take+notTake;
}




class Solution {
  public:
    int perfectSum(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return solve(nums,0,target,dp);
    }
};