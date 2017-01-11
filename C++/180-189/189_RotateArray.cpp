class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k = k % nums.size();
        }
        vector<int> tmp;
        int t = k;
        for (int i = nums.size() - k ; k != 0; k--){
            tmp.push_back(nums[i]);
            i++;
        }
        for(int i = 0; i < nums.size() - t; i++){
            tmp.push_back(nums[i]);
        }
        for(int i = 0; i <nums.size(); i++ ){
            nums[i] = tmp[i];
        }
        return;
    }
};