class Solution {
public:
    bool isValid(string s) {
        if (s == "" || s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        }
        stack<char> container;
        for (char x : s) {
            if (x == '(' || x == '[' || x == '{') {
                container.push(x);
            }
            else {
                if (container.empty()) {
                    return false;
                } else {
                    if (x == ')') {
                        if (container.top() == '(') {
                            container.pop();
                        } else {
                            return false;
                        }
                    }
                    if (x == '}') {
                        if (container.top() == '{') {
                            container.pop();
                        } else {
                            return false;
                        }
                    }
                    if (x == ']') {
                        if (container.top() == '[') {
                            container.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        if (!container.empty()) {
            return false; 
        }
        return true;
    }
};