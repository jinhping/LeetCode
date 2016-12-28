class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start + 1 < end){
            mid = start + (end - start) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[end]){
                if(nums[mid] > target && nums[start] <= target){
                    end = mid;
                }else start = mid;
            }
            else if(nums[mid] < nums[end]){
                if(nums[mid] < target && nums[end] >= target){
                    start = mid;
                }else{
                    end = mid;
                }
            }
            else end--;
        }
        if (nums[start] == target || nums[end] == target) {
            return true;
        }
        return false;

    }
};