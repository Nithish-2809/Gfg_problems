void printSubsequences(int index,string s,vector<string>&ans,string res) {
    int n = s.length();
    if(index>=n) {
        ans.push_back(res);
        return;
    }
    
    printSubsequences(index+1,s,ans,res);
    printSubsequences(index+1,s,ans,res+s[index]);
    
    return;
}





class Solution {
  public:
    vector<string> powerSet(string &s) {
        // Code here
        vector<string>ans;
        string res = "";
        
        printSubsequences(0,s,ans,res);
        
        sort(ans.begin(),ans.end());
        
    return ans;
    }
};