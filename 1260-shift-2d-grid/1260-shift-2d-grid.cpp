class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int index = 0;
        int loc = 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                loc = (k + index) % (m * n);
                ans[(loc / n)][(loc % n)] = grid[i][j];
                index++;
            }
        }
        return ans;
    }
};