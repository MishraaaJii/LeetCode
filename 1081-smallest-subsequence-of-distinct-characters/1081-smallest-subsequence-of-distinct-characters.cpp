class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mpp;
        stack<char> st;
        vector<bool> seen(26, false);
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]] += 1;
        }
        char c;
        for(int i = 0; i < s.size(); i++){
            c = s[i];
            mpp[c]--;
            if(seen[c - 'a']) continue;
            while(!st.empty() && st.top() >= c && mpp[st.top()] > 0){
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            seen[c - 'a'] = true;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        for(int i = 0; i < ans.size()/2; i++){
            c = ans[i];
            ans[i] = ans[ans.size() - 1 - i];
            ans[ans.size() - 1 - i] = c;
        }
        return ans;
    }
};