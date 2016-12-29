class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size_s1 = s1.length();
        int size_s2 = s2.length();
        int size_s3 = s3.length();
        if (size_s3 != size_s1 + size_s2) {
            return false;
        } 
        vector<vector<bool>> results(size_s1 + 1, vector<bool>(size_s2 + 1));
        results[0][0] = true;
        for (int i = 1; i < size_s1 + 1; i++) {
            if (results[i-1][0] && s1[i-1] == s3[i-1]) {
                results[i][0] = true;
            } else {
                results[i][0] = false;
            }
        }
         for (int i = 1; i < size_s2 + 1; i++) {
            if ( results[0][i-1] &&  s2[i-1] == s3[i-1]) {
                results[0][i] = true;
            } else {
                results[0][i] = false;
            }
         }
         for (int i = 1; i < size_s1 + 1; i++) {
            for (int j = 1; j < size_s2 + 1; j++) {
                results[i][j] = ( results[i-1][j] && s1[i-1] == s3[i+j-1] ) 
                        ||  (results[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
         }
         return results[size_s1][size_s2];
    }
};