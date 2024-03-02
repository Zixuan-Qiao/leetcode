class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> target_map, substring_map;
        for(auto c : t) {
            target_map[c]++;
        }
        int required = target_map.size();
        int matched  = 0;

        int l = 0, r = 0;
        int l_min = 0;
        int curr_min = INT_MAX;

        while(r < s.size()) {
            substring_map[s[r]]++;
            if((target_map.find(s[r]) != target_map.end()) 
                && target_map[s[r]] == substring_map[s[r]]) {
                matched++;        
            }

            while(matched == required) {
                substring_map[s[l]]--;
                l++;
                if((target_map.find(s[l - 1]) != target_map.end()) 
                    && substring_map[s[l - 1]] < target_map[s[l - 1]]) {
                    matched--;
                    if(r - l + 2< curr_min) {
                        curr_min = r - l + 2;
                        l_min = l - 1;
                    }
                }
            }
            r++;
        }

        if(curr_min != INT_MAX) {
            return s.substr(l_min, curr_min);
        } else {
            return "";
        }
    }
};