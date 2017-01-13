class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int column = board[0].size();
        bool result = true;
    
        //check each row 
        for(int i = 0; i < row; i++){
            unordered_set<char> s;
            for(int j = 0; j < column; j++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) == s.end()){
                        s.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
        //check each col
        for(int i = 0; i < column; i++){
            unordered_set<char> s;
            for(int j = 0; j < row; j++){
                if(board[j][i] != '.'){
                    if(s.find(board[j][i]) == s.end()){
                        s.insert(board[j][i]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
        //check each box
        unordered_set<char> s1;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != '.'){
                    if(s1.find(board[i][j]) == s1.end()){
                        s1.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s2;
        for(int i = 0; i < 3; i ++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] != '.'){
                    if(s2.find(board[i][j]) == s2.end()){
                        s2.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s3;
        for(int i = 0; i < 3; i ++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] != '.'){
                    if(s3.find(board[i][j]) == s3.end()){
                        s3.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
        // SSSSSSSSSSSSSSSS
        unordered_set<char> s4;
        for(int i = 3; i < 6; i ++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != '.'){
                    if(s4.find(board[i][j]) == s4.end()){
                        s4.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s5;
        for(int i = 3; i < 6; i ++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] != '.'){
                    if(s5.find(board[i][j]) == s5.end()){
                        s5.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s6;
        for(int i = 3; i < 6; i ++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] != '.'){
                    if(s6.find(board[i][j]) == s6.end()){
                        s6.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
        ///////SSSS
        unordered_set<char> s7;
        for(int i = 6; i < 9; i ++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != '.'){
                    if(s7.find(board[i][j]) == s7.end()){
                        s7.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s8;
        for(int i = 6; i < 9; i ++){
            for(int j = 3; j < 6; j++){
                if(board[i][j] != '.'){
                    if(s8.find(board[i][j]) == s8.end()){
                        s8.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
    
    
        unordered_set<char> s9;
        for(int i = 6; i < 9; i ++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] != '.'){
                    if(s9.find(board[i][j]) == s9.end()){
                        s9.insert(board[i][j]);
                    }else{
                        result = false;
                        return false;
                    }
                }
            }
        }
        return result;
    }
};