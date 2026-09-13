class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        vector<int> values;

        for (auto& [x, f] : freq)
            values.push_back(x);

        sort(values.begin(), values.end());

        for (int i = 0; i < values.size(); i++) {
            for (int j = i + 1; j < values.size(); j++) {
                if (freq[values[i]] != freq[values[j]])
                    return {values[i], values[j]};
            }
        }

        return {-1, -1};
    }
};