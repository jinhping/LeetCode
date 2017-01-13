class Solution {
public:
    string reverseVowels(string s) {
        unsigned long j = s.length() - 1;
        for(unsigned long i = 0 ; i< s.length(); i++){
            while((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
                s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') && i < s.length()){
                i++;
            }
            while((s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
                s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U') && j > 0){
                j--;
            }
            if(j > i){
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }else{
                break;
            }
            j--;
        }
        return s;
    }
};