class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int minLength = Integer.MAX_VALUE;
        int sum = 0;
        int i = 0; 
        int j = 0;
        while (j < nums.length) {
            sum += nums[j];
            j++;
            while (sum >= s) {
                minLength = Math.min(minLength, j - i);
                sum -= nums[i];
                i++;
            }
        }
        return minLength == Integer.MAX_VALUE ? 0 : minLength;
    }
}