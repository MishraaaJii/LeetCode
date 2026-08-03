class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long cost = 0;
        vector<vector<long long>> costs(27, vector<long long>(27, 0));
        for(char i = 'a'; i <= 'z'; i++){
            for(char j = 'a'; j <= 'z'; j++){
                if(i == j) continue;

                char temp = i;
                //prev
                long long prev = 0;
                while(i != j){
                    prev += previousCost[i - 'a'];
                    if(i == 'a') i = 'z';
                    else i--;
                }
                i = temp;
                //next
                long long next = 0;
                while(i != j){
                    next += nextCost[i - 'a'];
                    if(i == 'z') i = 'a';
                    else i++;
                }
                i = temp;

                costs[i - 'a'][j - 'a'] = min(prev, next);
                
            }
        }

        for(int i = 0; i < s.size(); i++){
            cost += costs[s[i] - 'a'][t[i] - 'a'];
        }
        return cost;
    }
};