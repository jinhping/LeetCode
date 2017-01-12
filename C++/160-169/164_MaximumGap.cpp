//Solution 1, time complexity is very high, solution 2 uses Radix Sort to solve it in linear time
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};

//Solution 2
//Solution thought from https://discuss.leetcode.com/topic/22221/radix-sort-solution-in-java-with-explanation
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        // m is the maximal number in nums
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            m = max(m, nums[i]);
        }
        
        int exp = 1; // 1, 10, 100, 1000 ...
        int R = 10; // 10 digits
    
        vector<int> aux(nums.size());
        
        while (m / exp > 0) { // Go through all digits from LSB to MSB
            vector<int> count(R);
            
            for (int i = 0; i < nums.size(); i++) {
                count[(nums[i] / exp) % 10]++;
            }
            
            for (int i = 1; i < count.size(); i++) {
                count[i] += count[i - 1];
            }
            
            for (int i = nums.size() - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % 10]] = nums[i];
            }
            
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = aux[i];
            }
            exp *= 10;
        }
        
        int maxGap = 0;
        for (int i = 1; i < aux.size(); i++) {
            maxGap = max(maxGap, aux[i] - aux[i - 1]);
        }
         
        return maxGap;
    }
};