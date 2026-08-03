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
                int j = 0;
                while(dp[j] <= nums[i]) j++;
                dp[j] = nums[i];
            }
        }
        return nums.size() - dp.size();
    }
};