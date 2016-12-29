class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> results(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i < m + 1; i++) {
            results[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) {
            results[0][j] = j;
        }
        
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    results[i][j] = results[i - 1][j - 1];
                } else {
                    results[i][j] = 1 + min(results[i - 1][j - 1], min(results[i - 1][j], results[i][j - 1]));
                }
            }
        }
        return results[m][n];
    }
};