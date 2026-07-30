class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int best = -1;
        string ans = "";
        do{
            int hh = (arr[0] * 10) + arr[1];
            int mm = (arr[2] * 10) + arr[3];

            if(hh < 24 && mm < 60){
                int total = (hh * 60) + mm;
                if(total > best){
                    best = total;
                    ans = "";
                    ans += char(arr[0] + '0');
                    ans += char(arr[1] + '0');
                    ans += ":";
                    ans += char(arr[2] + '0');
                    ans += char(arr[3] + '0');
                }
            }

        } while(next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};