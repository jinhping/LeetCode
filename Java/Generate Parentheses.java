class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        if (n <= 0) return res;
        helper(res, "", n, n);
        return res;
    }
    
    public void helper(List<String> res, String path, int left, int right) {
        if (left == 0 && right == 0) {
            res.add(path);
            return;
        }
        if (left > 0) {
            helper(res, path + "(", left - 1, right);
        }
        if (right > 0 && left < right) {
            helper(res, path + ")", left, right - 1);
        }        
    }
}