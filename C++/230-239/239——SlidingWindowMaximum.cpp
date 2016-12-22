class Solution {
public:
    void enqueue(deque<int> &dq, int x) {
        while (!dq.empty() && x > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    
    void dequeue(deque<int> &dq, int x) {
        if (x == dq.front()) {
            dq.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        deque<int> dq;
        
        for (int i = 0; i < k - 1; i++) {
            enqueue(dq, nums[i]);
        }
        
        for (int i = k - 1; i < nums.size(); i++) {
            enqueue(dq, nums[i]);
            results.push_back(dq.front());
            dequeue(dq, nums[i - k + 1]);
        }
        return results;
    }
};