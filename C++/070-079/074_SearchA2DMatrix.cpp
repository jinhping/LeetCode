class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        
        int mid = 0;
        int start = 0;
        int end = m * n - 1;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (matrix[start / n][start % n] == target) {
            return true;
        } else if (matrix[end / n][end % n] == target) {
            return true; 
        }
        return false;
    }
};