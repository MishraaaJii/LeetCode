class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> nums(A.size()+1, 0);
        vector<int> ans(A.size(), 0);
        ans[0] = A[0] == B[0];
        nums[A[0]]++;
        nums[B[0]]++;
        for(int i = 1; i < A.size(); i++){
            ans[i] = ans[i-1];
            if(A[i] == B[i]){
                ans[i] += 1;
            } else {
                if(nums[A[i]]){
                    ans[i] += 1;
                }
                if(nums[B[i]]){
                    ans[i] += 1;
                }
            }
            nums[A[i]] += 1;
            nums[B[i]] += 1;
        }
        return ans;
    }
};