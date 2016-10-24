class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0 || nums.size() == 1) {
            return res;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if (m.find(tmp) != m.end()) {
                res.push_back(m[tmp]);
                res.push_back(i);
                return res;
            } else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};