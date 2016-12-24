//滚动数组
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};