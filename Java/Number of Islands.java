class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0 ||grid[0].length == 0) return 0;
        int m = grid.length;
        int n = grid[0].length;
        int num_islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
    
    public void DFS(char[][] grid, int x, int y) {
        grid[x][y] = '0';
        if (x > 0 && grid[x - 1][y] == '1') {
            DFS(grid, x - 1, y);
        }
        if (x < grid.length - 1 && grid[x + 1][y] == '1') {
            DFS(grid, x + 1, y);
        }
        if (y > 0 && grid[x][y - 1] == '1') {
            DFS(grid, x, y - 1);
        }
        if (y < grid[0].length - 1 && grid[x][y + 1] == '1') {
            DFS(grid, x, y + 1);
        }
    }
}