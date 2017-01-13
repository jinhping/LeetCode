class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                int left;
                int right;
                if (map.find(nums[i] - 1) != map.end()) {
                    left = map[nums[i] - 1];
                } else {
                    left = 0;
                }
                if (map.find(nums[i] + 1) != map.end()) {
                    right = map[nums[i] + 1];
                } else {
                    right = 0;
                }
                int sum = left + right + 1;
                map[nums[i]] = sum;
                res = max(res, sum);
                map[nums[i] - left] = sum;
                map[nums[i] + right] = sum;
            } else {
                continue;
            }

        }
        return res;
    }
};