//Notice that there are a sorted array half and a rotated half after rotation.
//We only need to find which part the target locates in,
//if it is not in one part, search the other half.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[start] < nums[mid]) {
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else  {
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        if (nums[start] == target) {
            return start;
        } else if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};