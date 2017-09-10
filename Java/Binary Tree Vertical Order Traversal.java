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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null ) return results;
        Map<Integer, ArrayList<Integer>> hmap = new HashMap<>();
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<Integer> cols = new LinkedList<>();
        nodes.add(root);
        cols.add(0);
        int min = 0;
        int max = 0;
        while(!nodes.isEmpty()) {
            TreeNode node = nodes.poll();
            int col = cols.poll();
            if (!hmap.containsKey(col)) {
                hmap.put(col, new ArrayList<Integer>());
            }
            hmap.get(col).add(node.val);
            if (node.left != null) {
                nodes.add(node.left);
                cols.add(col - 1);
                min = Math.min(min, col - 1);
            }
            if (node.right != null) {
                nodes.add(node.right);
                cols.add(col + 1);
                max = Math.max(max, col + 1);
            }
        }
        for (int i = min; i <= max; i++) {
            results.add(hmap.get(i));
        }  
        return results;
    }
}