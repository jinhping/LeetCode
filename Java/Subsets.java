class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null || nums.length == 0) return results;
        List<Integer> path = new ArrayList<>();
        helper(results, path, nums, 0);
        return results;
    }
    
    public void helper(List<List<Integer>> results, List<Integer> path, int[] nums, int pos) {
        results.add(new ArrayList<Integer>(path));
        for (int i = pos; i < nums.length; i++) {
            path.add(nums[i]);
            helper(results, path, nums, i + 1);
            path.remove(path.size() - 1);
        }
    }
}