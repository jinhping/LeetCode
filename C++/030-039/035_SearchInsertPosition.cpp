class Solution {
public:
    //find the first postion < target, so return need to +1;
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        if (target < nums[0]) {
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            }
        }
     
        if (nums[end] == target) {
            return end;
        }
        if (nums[end] < target) {
            return end + 1;
        }
        if (nums[start] == target) {
            return start;
        }
        return start + 1;

    }
};