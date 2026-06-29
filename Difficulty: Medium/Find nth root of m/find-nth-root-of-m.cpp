int operation(int n,int b) {
    int ans = 1;
    
    for(int i=1;i<=n;i++) {
        ans *= b;
    }
    
    return ans;
} 


class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int low = 0;
        int high = m;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            if(operation(n,mid)==m) return mid;
            else if(operation(n,mid)>m) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
    return -1;
    }
};