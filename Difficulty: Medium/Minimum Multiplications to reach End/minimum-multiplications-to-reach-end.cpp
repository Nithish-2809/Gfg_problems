class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        
        vector<int>dist(1000, INT_MAX);
        queue<pair<int,int>>q;
        
        dist[start] = 0;
        q.push({start,0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int steps = it.second;
            
            if(node == end)
                return steps;
            
            for(auto x : arr) {
                int newNode = (node * x) % 1000;
                
                if(steps + 1 < dist[newNode]) {
                    dist[newNode] = steps + 1;
                    q.push({newNode, steps + 1});
                }
            }
        }
        
        return -1;
    }
};