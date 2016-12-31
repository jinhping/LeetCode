class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<vector<char>> container(numRows);
        int length = s.length();
        int row = 0;
        int step = 1;
        for (int i = 0; i < length; i++) {
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            container[row].push_back(s[i]);
            row += step;
        }
        string result = "";
        for (int i = 0; i < numRows; i++) {
            for (unsigned long j = 0; j < container[i].size(); j++) {
                result += container[i][j];
            }
        }
        return result;      
    }
};