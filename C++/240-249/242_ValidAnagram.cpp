class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;
        
        vector <char> a;
        vector <char> b;
        for(int i = 0; i < s.size(); i++){
            a.push_back(s.at(i));
        }
        for(int i = 0; i < t.size(); i++){
            b.push_back(t.at(i));
        }
        sort(a.begin(), a.end());
        sort(b.begin(),b.end());
        for(int i = 0; i < s.size(); i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
};