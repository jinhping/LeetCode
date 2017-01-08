class Solution {
public:
    //if appears one time and not in twice, put in container one
    //if appears second time and not in ones, put in container two
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = ones ^ nums[i] & ~twos;
            twos = twos ^ nums[i] & ~ones;
        }
        return ones;
    }
};