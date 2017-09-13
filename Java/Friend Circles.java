class Solution {
    public int findCircleNum(int[][] M) {
        int N = M.length;
        boolean[] visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }
        int num_circles = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                num_circles++;
                visited[i] = true;
                DFS(M, visited, i);
            }
        }
        return num_circles;
    }
    
    public void DFS(int[][] M, boolean[] visited, int row) {
        for (int i = 0; i < M.length; i++) {
            if (!visited[i] && i != row && M[row][i] == 1) {
                visited[i] = true;
                DFS(M, visited, i);
            }
        }
    }
}