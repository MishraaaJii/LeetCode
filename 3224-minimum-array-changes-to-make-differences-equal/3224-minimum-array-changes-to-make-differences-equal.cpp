class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> X(k + 1, nums.size());
        vector<int> diff(k + 2, 0);
        for(int i = 0; i < nums.size()/2; i++){
            int a = nums[i];
            int b = nums[nums.size() - 1 - i];
            X[abs(a - b)] -= 1;
            int limit = max(max(a, b), k - min(a, b));
            diff[0]--;
            diff[limit + 1]++;
        }
        int ans = INT_MAX;
        for(int i = 0; i < X.size(); i++){
            if(i != 0) diff[i] += diff[i-1];
            X[i] += diff[i];
            ans = min(ans, X[i]);
        }
        return ans;
    }
};