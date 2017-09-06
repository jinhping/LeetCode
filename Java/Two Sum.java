class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hmap = new HashMap<>();
        int[] result = new int[2];
        if (nums == null || nums.length == 0) return result;
        for (int i = 0; i < nums.length; i++) {
            if (hmap.get(target - nums[i]) == null) {
                hmap.put(nums[i], i);
            } 
            else {
                result[0] = hmap.get(target - nums[i]);
                result[1] = i;
                return result;
            }
        }
        return result;
    }
}