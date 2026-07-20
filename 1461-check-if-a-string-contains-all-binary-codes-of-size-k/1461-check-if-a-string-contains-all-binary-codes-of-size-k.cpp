class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<int> mpp(1 << k, 0);
        int count = 0;
        if(s.size() <= k) return false;
        for(int i = 0; i <= s.size() - k; i++){
            int num = 0;
            // num calculation block
            for(int j = i; j < i + k; j++){
                num = num << 1;
                num += (s[j] - '0');
            }

            if(!mpp[num]){
                mpp[num] = 1;
                count += 1;
            }
            if(count == (1 << k)) return true;
        }
        return false;
    }
};