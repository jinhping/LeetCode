//Solution 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start < end) {
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            mid = start + (end - start) / 2;
            if (nums[mid] > nums[start]) {
                start = mid + 1;
            } else {
                start++;
                end = mid;
            }
        }
        return nums[start];
    }
};


//Solution 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid; 
        while (start + 1 < end) {
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (start != 0 && nums[start - 1] > nums[start]) {
            return nums[start];
        }
        if (end != 0 && nums[end - 1] > nums[end]) {
            return nums[end];
        }
        return nums[0];
    }
};