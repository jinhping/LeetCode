class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            int value = n & 1;
            if (value == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};