class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        for (int i = 0; i <= h - n; i++) {
            if (needle == haystack.substr(i, n))
                return i;
        }
        return -1;
    }
};