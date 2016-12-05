class UnionFind {
    private: 
        vector<int> father;
    public: 
        UnionFind (int n) {
            father.resize(n);
            for (int i = 0; i < father.size(); i++) {
                father[i] = i;
            }
        }
        
        int find(int x) {
            if (father[x] == x) {
                return x;
            }
            return father[x] = find(father[x]);
        }
        
        bool connect(int a, int b) {
            int roota = find(a);
            int rootb = find(b);
            if (roota != rootb) {
                father[roota] = rootb;
                return true;
            } else {
                return false;
            }
        }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() == 0 && n > 1) {
            return false;
        }
        UnionFind union_find(n);
        for (int i = 0; i < edges.size(); i++) {
            bool ifConnect = union_find.connect(edges[i].first, edges[i].second);
            if (ifConnect == false) {
                return false;
            }
        }
        int root = union_find.find(0);
        for (int i = 1 ; i < n; i++) {
            int rootOthers = union_find.find(i);
            if (root != rootOthers) {
                return false;
            }
        }
        return true;
    }
};