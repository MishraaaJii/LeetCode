class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<unordered_set<int>> s(grid.size() + grid[0].size() - 1);
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans[i][j] = s[(i - j) + grid[0].size() - 1].size();
                s[(i - j) + grid[0].size() - 1].insert(grid[i][j]);
            }
        }
        
        vector<unordered_set<int>> s2(grid.size() + grid[0].size() - 1);
        for(int i = grid.size()-1; i >= 0; i--){
            for(int j = grid[0].size()-1; j >= 0; j--){
                ans[i][j] = abs(ans[i][j] - (int)s2[(i - j) + grid[0].size() - 1].size());
                s2[(i - j) + grid[0].size() - 1].insert(grid[i][j]);
            }
        }

        return ans;
    }
};