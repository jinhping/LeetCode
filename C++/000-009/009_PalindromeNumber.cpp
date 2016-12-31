class Solution {
public:
    bool isPalindrome(int x) {
        string reverse = "";
        int t = abs(x) ;
        while(x){
            string tmp = to_string(x % 10);
            reverse = reverse.append(tmp);
            x = x / 10;
        }
        int y = atoi(reverse.c_str());
        if(t == y){
            return true;
        }
        else return false;
    }
};