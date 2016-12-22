class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> res;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                //index1 and index2 are not zero-based so we need to add 1 before return the result.
                res.push_back(start + 1);
                res.push_back(end + 1);
                return res;
            } else if (numbers[start] + numbers[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return res;
    }
};