/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
//Three cases:
//1. Same Points
//2. x coordinates are the same. For this case, slope cannot be calculated. Because that will be infinite.
//3. general slope 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> map;
            int samePoints = 1;
            for (int j = i + 1; j < points.size(); j++) {
                 if (points[i].x == points[j].x && points[i].y == points[j].y) {
                     samePoints++;
                 } else if (points[i].x == points[j].x) {
                     map[INT_MAX]++;
                 } else {
                     double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                     map[slope]++;
                 }
            }
            int localMax = 0;
            for (auto it = map.begin(); it != map.end(); it++) {
                localMax = max(localMax, it -> second);
            }
            localMax += samePoints;
            res = max(res, localMax);
        }
        return res;
    }
};