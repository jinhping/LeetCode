class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (candidates == null || candidates.length == 0) return res;
        List<Integer> path = new ArrayList<>();
        helper(res, path, candidates, target, 0, 0);
        return res;
    }
    
    public void helper(List<List<Integer>> res, List<Integer> path, int[] candidates, int target, int sum, int pos) {
        if (sum == target) {
            res.add(new ArrayList<Integer>(path));
            return;
        } else if (sum > target) return;
        for (int i = pos; i < candidates.length; i++) {
            sum += candidates[i];
            path.add(candidates[i]);
            helper(res, path, candidates, target, sum, i);
            sum -= path.get(path.size() - 1);
            path.remove(path.size() - 1);
        }
    }
}