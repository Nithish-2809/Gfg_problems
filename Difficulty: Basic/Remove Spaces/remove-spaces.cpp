class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans = "";
        
        for(auto it : s) {
            if(it==' ') continue;
            
            ans += it;
        }
        
    return ans;
    }
};