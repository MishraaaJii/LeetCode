class Solution {
public:
    int smallestNumber(int n, int t) {
        int p = 1;
        for(int i = n; i < INT_MAX; i++){
            p = 1;

            int temp = i;
            while(temp > 0){
                p *= temp % 10;
                temp = temp / 10;
            }

            if(p % t == 0) return i;
        }
        return -1;
    }
};