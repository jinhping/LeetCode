class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(tokens[i]);
            } else {
               string num2 = s.top();
               s.pop();
               string num1 = s.top();
               s.pop();
               int res;
               if (tokens[i] == "+") {
                   res = stoi(num1) + stoi(num2);
               } else if (tokens[i] == "-") {
                   res = stoi(num1) - stoi(num2);
               } else if (tokens[i] == "*") {
                   res = stoi(num1) * stoi(num2);
               } else if (tokens[i] == "/") {
                   res = stoi(num1) / stoi(num2);
               }
               s.push(to_string(res));
            }
        }
        return stoi(s.top());
    } 
};