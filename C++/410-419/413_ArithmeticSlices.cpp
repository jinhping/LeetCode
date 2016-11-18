class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        vector<int> res(A.size(), 0);
        if (A[2] - A[1] == A[1] - A[0]) {
            res[2] = 1;
        }
        int result = res[2];
        for (int i = 3; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                res[i] = res[i-1] + 1;
            }
            result += res[i];
        }
        return result;
    }
};