class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i = 0; i < nums.size(); i++){
            int start = nums[i];
            int end = i;
            string t = "";
             while(end+1 < nums.size() && nums[end + 1] == nums[end] + 1){
                end ++;
             }
            if(start == nums[end]){
                 t = to_string(start);
                 end++;
                 i = end;
                i --;

             }else{
                 t = to_string(start) + "->" + to_string(nums[end]);
                    i = end;
              }
             result.push_back(t);
        }
        return result;
    }
};