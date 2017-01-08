class Solution {
public:
    //sort
    //first,
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if ((i > 0) && (nums[i] == nums[i-1])) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    results.push_back(tmp);
                    while (nums[j] == nums[j + 1]) {
                         j++;
                    }
                    while (nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
            }
        }
        return results;
    }
};