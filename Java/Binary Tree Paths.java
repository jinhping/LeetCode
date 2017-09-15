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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> results = new ArrayList<>();
        if (root == null) return results;
        helper(results, "", root);
        return results;
    }
    
    private void helper(List<String> results, String path, TreeNode root) {
        if (root.left == null && root.right == null) results.add(path + root.val);
        if (root.left != null) helper(results, path + root.val + "->", root.left);
        if (root.right != null) helper(results, path + root.val + "->", root.right);    
    }
}