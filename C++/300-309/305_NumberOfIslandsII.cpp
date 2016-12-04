class UnionFind {
    private:
        vector<int> father;
        int count;
    public: 
        UnionFind (int n) {
            father.resize(n + 1);
            for (int i = 1; i < father.size(); i++) {
                father[i] = i;
            }
        }
        
        int find(int x) {
            if (father[x] == x) {
                return x;
            }
            return father[x] = find(father[x]);
        }
        
        void connect(int a, int b) {
            int roota = find(a);
            int rootb = find(b);
            if (roota != rootb) {
                father[roota] = rootb;
                count--;
            }
        }
        
        int query() {
            return count;
        }
        
        void set_count(int total) {
            count = total;
        }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> results;
        if (n == 0) {
            return results;
        }
        if (m == 0) {
            return results;
        }
        if (positions.size() == 1) {
            results.push_back(1);
            return results;
        }
        vector<vector<bool>> grid(m, vector<bool>(n));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = 0;
            }
        } 
        UnionFind union_find(n * m);
        int size;
        for (int x = 0; x < positions.size(); x++) {
            if (x == 0) {
                union_find.set_count(x + 1);
            } else {
                union_find.set_count(size + 1);
            }
            
           
            grid[positions[x].first][positions[x].second] = 1;
        
            int i = positions[x].first;
            int j = positions[x].second;
            
            if (i > 0 && grid[i - 1][j]) {
                union_find.connect(i * n + j, (i - 1) * n + j);
            }
            if (i < m - 1 && grid[i + 1][j]) {
                union_find.connect(i * n + j, (i + 1) * n + j);
            }
            if (j > 0 && grid[i][j - 1]) {
                union_find.connect(i * n + j, i * n + j - 1);
            }
            if (j < n - 1 && grid[i][j + 1]) {
                union_find.connect(i * n + j, i * n + j + 1);
            }
            results.push_back(union_find.query());
            size = union_find.query();
        }
        
        return results;
    }
};