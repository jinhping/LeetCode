class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null || nums.length == 0) return results;
        List<Integer> path = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        for (int i = 0; i < visited.length; i++) {
            visited[i] = false;
        }
        Arrays.sort(nums);
        helper(results, path, nums, visited);
        return results;
    }
    
    private void helper(List<List<Integer>> results, List<Integer> path, int[] nums, boolean[] visited) {
        if (path.size() == nums.length) {
            results.add(new ArrayList<Integer>(path));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                continue;
            }
            visited[i] = true;
            path.add(nums[i]);
            helper(results, path, nums, visited);
            path.remove(path.size() - 1);
            visited[i] = false;
        }
    }
}