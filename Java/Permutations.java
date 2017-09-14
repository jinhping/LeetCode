class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null || nums.length == 0) return results;
        List<Integer> path = new ArrayList<>();
        helper(results, path, nums);
        return results;
    }
    
    public void helper(List<List<Integer>> results, List<Integer> path, int[] nums) {
        if (path.size() == nums.length) {
            results.add(new ArrayList<>(path));
        }
        for (int i = 0; i < nums.length; i++) {
            if (path.contains(nums[i])) continue;
            path.add(nums[i]);
            helper(results, path, nums);
            path.remove(path.size() - 1);
        }
    }
}