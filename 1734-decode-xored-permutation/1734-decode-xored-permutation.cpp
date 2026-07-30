class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int req = 0;
        for(int i = 1; i < encoded.size()+2; i++){
            req = req ^ i;
        }

        vector<int> ans(encoded.size() + 1, 0);
        for(int i = 1; i < encoded.size(); i += 2){
            ans[0] ^= encoded[i];
        }
        ans[0] ^= req; 
        for(int i = 1; i < ans.size(); i++){
            ans[i] = ans[i-1] ^ encoded[i-1];
        }
        return ans;
    }
};