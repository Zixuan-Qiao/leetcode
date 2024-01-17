class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"abc", "def", "ghi", "jkl", 
                            "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> r;
        if(digits.size() == 0)
            return r;
        r.push_back("");
        for(int i = 0; i < digits.size(); i++){
            int index = digits[i] - '0' - 2;
            int boundry = r.size(); 
            for(int j = 0; j < boundry; j++){
                int k;
                for(k = 0; k < v[index].size() - 1; k++){
                    r.push_back(r[j] + v[index][k]);
                }
                r[j] += v[index][k];
            }
        }
        return r;
    }
};