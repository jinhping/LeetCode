//Solution 1
class Solution {
public:
    // a^b^b =a   XOR
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};


//Solution 2 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = (0 + n + 1) * n / 2;
        for (auto x : nums) {
            sum -= x;
        }
        return sum;
    }
};