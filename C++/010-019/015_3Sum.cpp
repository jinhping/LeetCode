class Solution {
public:
    void helper (vector<vector<int>> &results, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    results.push_back(tmp);
                    while (j < k && nums[j + 1] == nums[j]) {
                        j++;
                    }
                    while (j < k && nums[k - 1] == nums[k]) {
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
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        helper(results, nums);
        return results;
    }
};