class Solution {
  public:
    void rotate(vector<int> &nums) {
        // code here
        int n = nums.size();
        
        int firstEl = nums[n-1];
        
        for(int i=n-1;i>0;i--) {
            nums[i] = nums[i-1];
        }
        
        nums[0] = firstEl;
    }
};