class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i%3 == 0 && i%5 == 0) {
                string tmp = "FizzBuzz";
                res.push_back(tmp);
            } else if (i%3 == 0 || i%5 == 0) {
                if (i%3 == 0) {
                    string tmp = "Fizz";
                    res.push_back(tmp);
                } else {
                    string tmp = "Buzz";
                    res.push_back(tmp);
                }
            } else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};