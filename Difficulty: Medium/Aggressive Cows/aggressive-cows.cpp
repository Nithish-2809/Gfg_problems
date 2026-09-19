bool distancePossible(vector<int>& nums, int k, int mid) {
    int cows = 1;
    int lastCow = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] - lastCow >= mid) {
            cows++;
            lastCow = nums[i];
        }
    }

    return cows >= k;
}



class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int low = 1;
        sort(arr.begin(),arr.end());
        int high = arr[n-1]-arr[0];
        int ans;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            if(distancePossible(arr,k,mid)){
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        
    return ans;
    }
};