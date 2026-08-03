class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int temp = dp.back();
            if(nums[i] >= temp){
                dp.push_back(nums[i]);
            } else {
                auto it = upper_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return nums.size() - dp.size();
    }
};