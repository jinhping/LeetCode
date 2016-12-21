class Solution {
public:
    //prestore left highest on a particular element
    //then prestore right highest on a particular element;
    //calculate the water stored
    int trap(vector<int>& height) {
        int size = height.size(); 
        if (size == 0) {
            return 0;
        }
        int left[size];
        int right[size];
        
        left[0] = height[0];
        for (int i = 1; i < size; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        
        right[size-1] = height[size-1];
        for (int i = size - 2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};