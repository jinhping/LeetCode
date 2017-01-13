class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }
        vector<int> result;
        int i = 0;
        for( i = 0; i < nums.size(); i++ ){
            if(m[nums[i]] == 1){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};