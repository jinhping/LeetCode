class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(unsigned long i = 0; i < nums1.size(); i++){
            s1.insert(nums1[i]);
        }
        for(unsigned long i = 0; i < nums2.size(); i++){
            s2.insert(nums2[i]);
        } 
        vector<int> result;
        for(auto i = s2.begin(); i != s2.end(); i++){
            if(s1.find(*i) != s1.end()){
                result.push_back(*i);
            }
        }
        return result;
    }
};