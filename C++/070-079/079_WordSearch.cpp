class Solution {
public:
    bool isFound(vector<vector<char>> &board, const char * w, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != *w || board[x][y] == '\0') {
            return false;
        }
        if (*(w + 1) == '\0') {
            return true;
        }
        char tmp = board[x][y];
        board[x][y] = '\0';
        if (isFound(board, w+1, x+1, y) ||
            isFound(board, w+1, x, y+1) ||
            isFound(board, w+1, x-1, y) ||
            isFound(board, w+1, x, y-1)) {
            return true;
        }
        board[x][y] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size(); 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isFound(board, word.c_str(), i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};