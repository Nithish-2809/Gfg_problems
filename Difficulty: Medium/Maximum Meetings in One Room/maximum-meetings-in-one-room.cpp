class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

        vector<vector<int>> data;
        vector<int> ans;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            data.push_back({s[i], f[i], i});
        }

        sort(data.begin(), data.end(), comp);

        ans.push_back(data[0][2] + 1);

        int finishTime = data[0][1];

        for (int i = 1; i < n; i++) {
            if (data[i][0] > finishTime) {
                ans.push_back(data[i][2] + 1);
                finishTime = data[i][1];
            }
        }

        sort(ans.begin(), ans.end());  

        return ans;
    }
};