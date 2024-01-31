class Solution {
public:
    void addOneParenthese(vector<string>& v, int l, int r, string& s){
        if (l + r == 0) {
            v.push_back(s);
            return;
        } else if (l == r) {
            s += "(";
            l--;
            addOneParenthese(v, l, r, s);
        } else if (l == 0) {
            s += ")";
            r--;
            addOneParenthese(v, l, r, s);
        } else {
            string tmp(s);
            s += "(";
            addOneParenthese(v, l - 1, r, s);
            tmp += ")";
            addOneParenthese(v, l, r - 1, tmp);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> r;
        string base = "(";
        addOneParenthese(r, n - 1, n, base);
        return r;
    }
};