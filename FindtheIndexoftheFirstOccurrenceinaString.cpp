class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        for (int i = 0; i <= h - n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (needle[j] != haystack[i + j])
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};