class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> mpp(26, 0);
        stack<char> st;
        vector<bool> seen(26, false);
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            mpp[s[i] - 'a'] += 1;
        }
        char c;
        for(int i = 0; i < s.size(); i++){
            c = s[i];
            mpp[c - 'a']--;
            if(seen[c - 'a']) continue;
            while(!st.empty() && st.top() >= c && mpp[st.top() - 'a'] > 0){
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