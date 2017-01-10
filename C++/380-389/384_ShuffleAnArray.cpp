class Solution {
private: 
    vector<int> tmp;

public:
    Solution(vector<int> nums) {
        tmp = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return tmp;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = tmp;
        for (int i = 0; i < res.size(); i++) {
            int pos = rand() % (res.size() - i);
            swap(res[pos + i], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */