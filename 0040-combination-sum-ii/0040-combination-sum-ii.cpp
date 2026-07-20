class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        comb(candidates, target, 0, ans, curr);
        return ans;
    }
    void comb(vector<int>& candidates, int target, int index,
              vector<vector<int>>& ans, vector<int>& curr) {
        if (!target) {
            ans.push_back(curr);
            return;
        }
        if (index == candidates.size())
            return;
        if (target < candidates[index])
            return;

        // notTake
        int newIndex = index;
        while (newIndex < candidates.size() &&
               candidates[index] == candidates[newIndex])
            newIndex++;
        comb(candidates, target, newIndex, ans, curr);
        // take
        curr.push_back(candidates[index]);
        target = target - candidates[index];
        comb(candidates, target, index + 1, ans, curr);
        curr.pop_back();
        return;
    }
};