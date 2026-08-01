bool solve(vector<int>arr,int index,int sum,vector<vector<int>>&dp) {
    int n = arr.size();
    if(sum==0) return true;
    if(index==n-1) return (sum==arr[index]);
    
    if(dp[index][sum]!=-1) return dp[index][sum];
    
    int take = false;
    if(arr[index]<=sum) {
        take = solve(arr,index+1,sum-arr[index],dp);
    }
    
    int notTake = solve(arr,index+1,sum,dp);
    
    return dp[index][sum] = take || notTake;
}






class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        
        
        return solve(arr,0,sum,dp);
    }
};