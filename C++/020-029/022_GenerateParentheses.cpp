//Solution 1
class Solution {
public:
   bool checkValid(string s ){
        int count1 = 0;
        int count2 = 0;
        bool result = true;
        for(unsigned long i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                count1 ++;
            }else{
                count2 ++;
            }
    
            if(count2 > count1){
                result = false;
                return false;
            }
        }
        return true;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        for(int i = 0; i < n; i++ ){
            s = s + "(";
        }
        for(int i = 0; i < n; i++ ){
            s = s + ")";
        }
    
        do{
            if(s[0] == ')' || s[s.length() -1 ] == '('){
                continue;
            }else{
                bool t = true;
                t = checkValid(s);
                if(t==true){
                    v.push_back(s);
                }
            }
        }while(next_permutation(s.begin(),s.end()));
        
        return v;
    }
};