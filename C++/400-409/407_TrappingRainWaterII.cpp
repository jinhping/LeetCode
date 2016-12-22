class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0) {
            return 0;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int row = heightMap.size();
        int col = heightMap[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int result = 0;
        int Max = INT_MIN;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!(i==0 || i==row - 1 || j ==0 || j == col-1)) {
                    continue;
                }
                pq.push(make_pair(heightMap[i ][j], i*col+j));
                visited[i][j] = 1;
            }
        }
        
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()) {
            auto val = pq.top();
            pq.pop();
            int height = val.first;
            int x = val.second/col;
            int y = val.second%col;
            Max = max(Max, height);
            for (auto d : directions) {
                int x2 = x + d[0];
                int y2 = y + d[1];
                if (x2>=row || x2<0 || y2<0 || y2>=col || visited[x2][y2]) continue;
                visited[x2][y2] = 1;
                if (heightMap[x2][y2] < Max) {
                    result += Max - heightMap[x2][y2];
                }
                pq.push(make_pair(heightMap[x2][y2], x2 * col + y2));
            }
        }
        return result;
    }
};