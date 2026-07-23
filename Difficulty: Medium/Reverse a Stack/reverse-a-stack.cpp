class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        int n = st.size();
        vector<int>temp;
        
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        
        for(auto it : temp) {
            st.push(it);
        }
    }
};