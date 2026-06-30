class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        
        
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                        >minHeap;
                        
        
        map<int,int>mp;
        
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        for(auto it : mp) {
            minHeap.push({it.second,it.first});
            
            if(minHeap.size()>k) {
                minHeap.pop();
            }
        }
        
        vector<int>ans;
        
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
    return ans;
    }
};
