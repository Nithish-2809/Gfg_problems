int solve(vector<int>nums,int index,int sum,vector<vector<int>>&dp) {
    int n = nums.size();
    if(index==n) {
        return (sum==0);
    }
    
    if(dp[index][sum]!=-1) return dp[index][sum];
    
    
    int notTake = solve(nums,index+1,sum,dp);
    int take = 0;
    if(nums[index]<=sum) {
        take = solve(nums,index+1,sum-nums[index],dp);
    }
    
    return dp[index][sum] = take + notTake;
}


class Solution {
  public:
    int countPartitions(vector<int>& nums, int diff) {
        // Code here
        int n = nums.size();
        
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        
        if((sum-diff)<0 || (sum-diff)%2!=0) return 0;
        
        vector<vector<int>>dp(n,vector<int>(500,-1));
        
        
        
    return solve(nums,0,(sum-diff)/2,dp);
    }
};