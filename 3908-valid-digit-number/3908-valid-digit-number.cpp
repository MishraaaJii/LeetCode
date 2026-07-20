class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false;
        while(n > 0){
            if(n%10 == x){
                if(n < 10) return false;
                flag = true;
            }
            n = n/10;
        }
        return flag;
    }
};