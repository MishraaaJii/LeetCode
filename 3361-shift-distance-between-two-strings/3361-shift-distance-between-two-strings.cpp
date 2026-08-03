class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long cost = 0;
        for(int i = 0; i < s.size(); i++){
            char temp = s[i];
            //prev
            long long prev = 0;
            while(s[i] != t[i]){
                prev += previousCost[s[i] - 'a'];
                if(s[i] == 'a') s[i] = 'z';
                else s[i]--;
            }
            s[i] = temp;
            //next
            long long next = 0;
            while(s[i] != t[i]){
                next += nextCost[s[i] - 'a'];
                if(s[i] == 'z') s[i] = 'a';
                else s[i]++;
            }
            cost += min(prev, next);
        }
        return cost;
    }
};