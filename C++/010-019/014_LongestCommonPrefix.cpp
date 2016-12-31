class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int size = strs.size();
        if (size == 0) {
            return "";
        } else if (size == 1) {
            return strs[0];
        }
        int maxSize = strs[0].length();
        int i = 0;
        int j = 0;
        for (i = 0; i < maxSize; i++) {
            if(strs[i] == ""){
                return "";
            }
            for (j = 0; j < size; j++) {
                if (strs[0][i] != strs[j][i] ) {
                    break;
                }
            }
            if(j == size) {
                j--;
            }
         
            if(j == size - 1 && strs[0][i] == strs[j][i]){
                result = result + strs[0][i];
            }
            else {
                break;
            }
        }
        return result;
    }
};