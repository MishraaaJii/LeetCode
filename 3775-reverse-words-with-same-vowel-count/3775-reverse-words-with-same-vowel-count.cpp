class Solution {
public:
    string reverseWords(string s) {
        int count = 0;
        string ans = "";
        int curr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                curr = i;
                break;
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
            ans += s[i];
        }
        if(s[curr] != ' ') return s;
        for(int i = curr + 1; i < s.size(); i++){
            int tempCount = 0;
            int j = i;
            for(; j < s.size(); j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') tempCount++;
                if(s[j] == ' '){
                    j--;
                    break;
                }
            }
            if(j == s.size()) j--;
            ans += ' ';
            if(tempCount == count) ans += reverse(s, i, j);
            else ans.append(s.begin() + i, s.begin() + j + 1);
            i = j + 1;
        }

        return ans;
    }
    string reverse(string& original, int start, int end){
        string temp = "";
        while(end >= start){
            temp += original[end];
            end--;
        }
        return temp;
    }
};