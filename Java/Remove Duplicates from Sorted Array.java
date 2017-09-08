class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int prev = nums[0];
        int index = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != prev) {
                nums[index] = nums[i];
                prev = nums[i];
                index++;
            }
        }
        return index;
    }
}