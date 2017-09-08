class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int result = 0;
        if (nums == null || nums.length <= 2) return result;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int start = i + 1;
            int end = nums.length - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum < target) {
                    result += end - start;
                    start++;
                } else {
                    end--;
                }
            }
        }
        return result;
    }
}