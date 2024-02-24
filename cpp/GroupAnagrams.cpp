class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result{{strs[0]}};
        vector<unordered_multiset<char>> comparison{unordered_multiset<char>(strs[0].cbegin(), strs[0].cend())};

        for(int i = 1; i < strs.size(); i++) {
            unordered_multiset<char> temp(strs[i].cbegin(), strs[i].cend());
            int j;
            for(j = 0; j < comparison.size(); j++) {
                if(temp == comparison[j]) {
                    result[j].push_back(strs[i]);
                    break;
                }
            }
            if(j == comparison.size()) {
                comparison.push_back(temp);
                result.push_back({strs[i]});
            }
        }

        return result;

    }
};