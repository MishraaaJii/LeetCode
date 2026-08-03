class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long cost = 0;
        vector<vector<long long>> costs(26, vector<long long>(26, INT_MAX));
        for(char i = 'a'; i <= 'z'; i++){
            char curr = i;

            //clockwise
            long long cost = 0;
            do{
                cost += nextCost[curr - 'a'];
                if(curr == 'z') curr = 'a';
                else curr++;
                costs[i - 'a'][curr - 'a'] = cost;
            } while(curr != i);

            //counterclockwise
            cost = 0;
            curr = i;
            do{
                cost += previousCost[curr - 'a'];
                if(curr == 'a') curr = 'z';
                else curr--;
                costs[i - 'a'][curr - 'a'] = min(costs[i - 'a'][curr - 'a'], cost);
            } while(curr != i);
            costs[i - 'a'][i - 'a'] = 0;
        }

        for(int i = 0; i < s.size(); i++){
            cost += costs[s[i] - 'a'][t[i] - 'a'];
        }
        return cost;
    }
};