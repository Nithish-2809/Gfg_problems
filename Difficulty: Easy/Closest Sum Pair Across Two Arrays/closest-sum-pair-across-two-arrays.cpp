class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        int i = 0;
        int j =n2-1;
        int diff = INT_MAX;
        vector<int>ans(2,-1);
        
        while(i<n1 && j>=0) {
            int currSum = arr1[i]+arr2[j];
            int currDiff = abs(x-currSum);
            
            if(currDiff<diff) {
                diff = currDiff;
                ans[0] = arr1[i];
                ans[1] = arr2[j];
            }
            
            if(currSum<x) {
                i++;
            }
            else {
                j--;
            }
        }
    return ans;
    }
};