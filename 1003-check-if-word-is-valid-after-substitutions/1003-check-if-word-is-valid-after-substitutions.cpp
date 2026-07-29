class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string t = "abc";
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
            if(!st.empty() && st.top() == t[t.size() - 1]){
                for(int j = t.size() - 1; j >= 0; j--){
                    if(!st.empty() && st.top() == t[j]) st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};