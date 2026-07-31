class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char, int>> st;
        string ans = "";
        int limit = 0;

        for(int i = 0; i < s.size(); i++){
            if(st.empty() || s[i] != st.top().first){
                st.push({s[i], 1});
            } else {
                pair<char, int> temp = {st.top().first, st.top().second + 1};
                st.pop();
                st.push(temp);
            }
            if(!st.empty() && st.top().first == ')' && st.top().second == k){
                pair<char, int> temp = st.top();
                st.pop();
                if(!st.empty() && st.top().first == '(' && st.top().second >= k){
                    if(st.top().second == k) st.pop();
                    else{
                        temp = {st.top().first, st.top().second - k};
                        st.pop();
                        st.push(temp);
                    }
                } else {
                    st.push(temp);
                }
            }
        }
        while(!st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};