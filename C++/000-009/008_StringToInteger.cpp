class Solution {
public:
    int myAtoi(string str) {
       long result = 0;
       int indicator = 1; // means positive number
       int i = 0; 
       while (i < str.length()) {
           int i = str.find_first_not_of(' '); //escape all leading ' '
           if (str[i] == '-') {
               indicator = -1;
               i++;
           } else if (str[i] == '+') {
               indicator = 1;
               i++;
           }
           while ('0' <= str[i] && str[i] <= '9') {
               result = result * 10 + (str[i] - '0');
               cout << "result: " << result << endl;
               cout << "indicator: " <<  indicator << endl;
               if (result * indicator >= INT_MAX) {
                    return INT_MAX;
               } else if ( result * indicator <= INT_MIN) {
                   return INT_MIN;
               }
               i++;
           }
           return result * indicator;
       }
       return result * indicator;
    }
};