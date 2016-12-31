class Solution {
public:
    bool isHappy(int n) {
       int tmp = n;
        int result = 0;
        while(tmp){
            result = (tmp%10)*(tmp%10) + result;
            tmp = tmp/10;
        }   
        result = result + tmp*tmp;
        tmp = result;
        int count = 50;
        while(result != 1){
            result = 0;
            while(tmp){
             result = (tmp%10)*(tmp%10) + result;
             tmp = tmp/10;
            }   
            result = result + tmp*tmp;
            tmp =result;
            count --;
            if(count == 0){
                return false;
            }
        }
        if(result == 1 )return true;
        else return false;
        }
};