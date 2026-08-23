class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        
        int n = arr.size();
        
        vector<int>prefixSum(n,0);
        prefixSum[0] = arr[0];
        
        for(int i=1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1]+arr[i];
        }
        
        for(auto it : queries) {
            int l = it[0];
            int r = it[1];
            
            int sum = 0;
            if(l==0) sum = prefixSum[r];
            else {
                sum = prefixSum[r]-prefixSum[l-1];
            }
            
            int avg = sum/(r-l+1);
            
            ans.push_back(avg);
        }
        
        
    return ans;
    }
};