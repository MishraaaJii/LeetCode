class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 0, 0, 0);
    }
    bool solve(vector<int>& nums, int start, int end, int p1, int p2, int turn){
        if(start > end) return p1 >= p2;
        int ans;
        if(turn % 2 == 0)
        {
            ans = false;
            //player 1 turn

            //take from start
            ans = ans || solve(nums, start + 1, end, p1 + nums[start], p2, turn + 1);
            //take from end
            if(start != end) ans = ans || solve(nums, start, end - 1, p1 + nums[end], p2, turn + 1);
        } else {
            ans = true;
            //player 2 turn

            //take from start
            ans = ans && solve(nums, start + 1, end, p1, p2 + nums[start], turn + 1);
            //take from end
            if(start != end) ans = ans && solve(nums, start, end - 1, p1, p2 + nums[end], turn + 1);
        }
        return ans;
    }
};