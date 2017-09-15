/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) return results;
        List<Integer> path = new ArrayList<>();
        helper(results, path, root, sum);
        return results;
    }
    
    private void helper(List<List<Integer>> results, List<Integer> path, TreeNode root, int sum) {
        if (root.left == null && root.right == null && root.val == sum) {
            path.add(root.val);
            results.add(new ArrayList<Integer>(path));
            path.remove(path.size() - 1);
            return;
        }
        if (root.left != null) {
            path.add(root.val);
            helper(results, path, root.left, sum - root.val);
            path.remove(path.size() - 1);
        }
        if (root.right != null) {
            path.add(root.val);
            helper(results, path, root.right, sum - root.val);
            path.remove(path.size() - 1);
        }
    }
}