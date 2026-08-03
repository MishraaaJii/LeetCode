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
                dp[binarySearch(dp, nums[i])] = nums[i];
            }
        }
        return nums.size() - dp.size();
    }
    int binarySearch(vector<int>& dp, int num){
        int start = 0;
        int end = dp.size() - 1;
        int mid;
        int index = -1;
        while(start <= end){
            mid = (start + end)/2;
            if(dp[mid] > num){
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return index;
    }
};