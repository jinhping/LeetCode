class Solution {
private: 
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};

public:
    string helper (int num) {
        if (num == 0) {
            return "";
        }
        else if (num < 20) {
            return LESS_THAN_20[num] + " ";
        }
        else if (num < 100) {
            return TENS[num / 10] + " " + helper(num % 10);
        }
        else 
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }
    
    void trim(string& s)
    {
      size_t p = s.find_first_not_of(" \t");
      s.erase(0, p);
   
      p = s.find_last_not_of(" \t");
      if (string::npos != p) s.erase(p+1);
    }
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        int i = 0;
        string words = "";
        while (num > 0) {
            if (num % 1000 != 0) {
                words = helper(num % 1000) + THOUSANDS[i] + " " + words; 
            }
            num = num / 1000;
            i++;
        }
        trim(words);
        return words;
    }
    
};