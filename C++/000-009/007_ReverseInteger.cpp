class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool hasNegative = false;
        if(s[0] == '-'){
            hasNegative = true;
        }
    
        if(hasNegative){
            int a = abs(x);
            s = to_string(a);
            string t = ""; 
            for(unsigned long i = s.length() -1; i != 0 ; i --){
                t += s[i];
            }
            t += s[0];
            string b = '-' + t;
            long long c = stoll(b);
            if(c < INT_MIN){
                return 0;
            }
            return stoi(b);
        }else{
            string t = ""; 
            for(unsigned long i = s.length() -1; i != 0 ; i --){
                t += s[i];
            }
            t += s[0];
            long long c = stoll(t);
            if(c > INT_MAX){
                return 0;
            }
            return stoi(t);
        }
    }
};