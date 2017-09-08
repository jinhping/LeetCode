class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int sum = 0; 
        int maxLength = 0;
        HashMap<Integer, Integer> hmap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sum == k) maxLength = i + 1;
            else if (hmap.containsKey(sum - k)) maxLength = Math.max(maxLength, i - hmap.get(sum - k));
            if (!hmap.containsKey(sum)) hmap.put(sum, i);
        }
        return maxLength;
    }
}