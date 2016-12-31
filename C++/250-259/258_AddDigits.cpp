//Solution 1
class Solution {
public:
    int addDigits(int num) {
       return (num - 1)%9 + 1;
    }
};


//Solution 2
class Solution {
public:
    int addDigits(int num) {
        if (num < 10 ) return num;
        int result = 0;
        while( num >= 10 ){
            result = num%10 + result;
            num = num/10;
        }
        result = result + num;
        while(result >= 10){
            return  addDigits(result);
        }
        return result;
    }
};