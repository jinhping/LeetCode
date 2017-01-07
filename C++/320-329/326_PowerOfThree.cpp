//Solution 1
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0){
            n = n/3;
        }
        
        if(n == 1){
            return true;
        }
        else return false;
    }
};

//Solution 2
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 && 1162261467 % n == 0);
    }
};