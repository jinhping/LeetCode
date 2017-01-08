class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string> ();
        }
        vector<string> result;
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
        
        for(int i = 0; i < digits.length(); i++) {
            int num = digits[i] - '0';
            if (num < 0 || num > 9) {
                break;
            }
            string candidate = v[num];
            if (candidate.empty()) {
                continue;
            }
            vector<string> tmp;
            for (int j = 0; j < candidate.length(); j++) {
                for (int k = 0; k < result.size(); k++) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};