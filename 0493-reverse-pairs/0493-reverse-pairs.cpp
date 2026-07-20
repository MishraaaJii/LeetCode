class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        helper(nums, 0, nums.size()-1, count);
        return count;
    }
    void helper(vector<int>& nums, int left, int right, int& count) {
        if(left == right) return;
        int mid = (left + right) / 2;
        helper(nums, left, mid, count);
        helper(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }
    void merge(vector<int>& nums, int left, int mid, int right, int& count) {
        // checking pairs
        int checked = mid+1;
        for(int i = left; i <= mid; i++){
            for(int j = checked; j <= right; j++){
                if((long long)nums[i] > (2LL * nums[j])) {
                    count += (mid - i + 1);
                    checked = j+1;
                }
                else break;
            }
        }

        //merging
        int i = left;
        int j = mid+1;
        vector<int> temp;
        while(i <= mid && j <= right){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j++; 
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= right){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k = 0; k < temp.size(); k++){
            nums[left + k] = temp[k];
        }
    }
};