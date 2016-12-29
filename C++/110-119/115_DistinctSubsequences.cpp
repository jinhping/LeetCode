class Solution {
public:
    int numDistinct(string s, string t) {
        string S = s;
        string T = t;
        int size_S = S.length();
        int size_T = T.length();
        if (size_T == 0) {
            return 1;
        } else if (size_S == 0) {
            return 0;
        }
        vector<vector<int>> results(size_S + 1, vector<int>(size_T + 1));
        for (int i = 0; i < size_S + 1; i++) {
            results[i][0] = 1;
        }
        for (int i = 1; i < size_T + 1; i++) {
            results[0][i] = 0;
        }
        for (int i = 1; i < size_S + 1; i++) {
            for (int j = 1; j < size_T + 1; j++) {
                if (S[i-1] == T[j-1]) {
                    results[i][j] = results[i-1][j] + results[i-1][j-1];
                } else if (S[i-1] != T[j-1]) {
                    results[i][j] = results[i-1][j];
                }
            }
        }
        return results[size_S][size_T];
    }
};