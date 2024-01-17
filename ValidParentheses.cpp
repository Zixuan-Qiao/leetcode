class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        char c = s[0];
        if (c == ')' || c == ']' || c == '}')
            return false;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (stk.empty()) {
                return false;
            } else if (c == ')' && (stk.top() == '(')) {
                stk.pop();
            } else if (c == ']' && (stk.top() == '[')) {
                stk.pop();
            } else if (c == '}' && (stk.top() == '{')) {
                stk.pop();
            } else {
                return false;
            }
        }
        if (stk.empty())
            return true;
        else 
            return false;
    }
};