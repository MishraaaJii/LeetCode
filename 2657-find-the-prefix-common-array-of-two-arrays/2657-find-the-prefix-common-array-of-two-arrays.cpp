class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> sA;
        unordered_set<int> sB;
        vector<int> ans(A.size(), 0);
        ans[0] = A[0] == B[0];
        sA.insert(A[0]);
        sB.insert(B[0]);
        for(int i = 1; i < A.size(); i++){
            int count = ans[i-1];
            if(A[i] == B[i]){
                count++;
            } else {
                if(sA.find(B[i]) != sA.end()){
                    count++;
                }
                if(sB.find(A[i]) != sB.end()){
                    count++;
                }
            }
            sA.insert(A[i]);
            sB.insert(B[i]);
            ans[i] = count;
        }
        return ans;
    }
};