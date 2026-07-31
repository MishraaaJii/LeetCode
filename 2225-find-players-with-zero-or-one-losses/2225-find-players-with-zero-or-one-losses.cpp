class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> mpp;
        int last = 0;
        for(int i = 0; i < matches.size(); i++){
            mpp[matches[i][0]] += 0;
            mpp[matches[i][1]]++;
            last = max(max(last, matches[i][0]), matches[i][1]);
        }
        for(auto it : mpp){
            if(!it.second) ans[0].push_back(it.first);
            else if(it.second == 1) ans[1].push_back(it.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};