class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int low = 1;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            int count = 0;
            for (auto x : nums) {
                if (x <= mid) {
                    count++;
                }
            }
            if (count <= mid ) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};