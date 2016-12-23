//Solution 1: Priority Queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

//Solution 2: Quick Sort
class Solution {
public:
    void helper(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = nums[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        helper(nums, left, i - 1);
        helper(nums, i + 1, right);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        helper(nums, 0, size - 1);
        return nums[size - k];
    }
};

//Solution 3: Quick Select 
class Solution {
public:
    int kthLargestElement(int k, vector<int> nums){
        return helper(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
    
    int helper(vector<int> &nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        
        int i = left, j = right;
        int pivot = nums[(i + j) / 2];
        while (i <= j) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            while (i <= j && nums[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }


        if (left + k - 1 <= j) {
            return helper(nums, left, j, k);
        }
        
        if (left + k - 1 < i) {
            return nums[left + k - 1];
        }

        return helper(nums, i, right, k - (i - left));
    }
};

