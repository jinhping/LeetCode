class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i = 0; i <= num; i++){
            result.push_back(__builtin_popcount(i));
        }
        return result;
    }
};