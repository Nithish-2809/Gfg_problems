class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n1 = arr.size();
        int n2 = dep.size();
        
        int i = 0;
        int j = 0;
        int platforms = 0;
        int maxPlatforms = INT_MIN;
        
        while(i<n1 && j<n2) {
            if(arr[i]<=dep[j]) {
                platforms++;
                i++;
            }
            else {
                platforms--;
                j++;
            }
            
            maxPlatforms = max(maxPlatforms,platforms);
        }
    
    
    return maxPlatforms;
    }
};
