class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                int new_left = left + 1;
                while (new_left < right && height[new_left] <= height[left]) {
                    new_left++;
                }
                left = new_left;
            } else {
                int new_right = right - 1;
                while (left < new_right && height[new_right] <= height[right]) {
                    new_right--;
                }
                right = new_right;        
            }
        }
        return res;
    }
};