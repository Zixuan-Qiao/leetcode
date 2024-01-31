#define ASCII_MAX 128

int lengthOfLongestSubstring(char * s){

    int left = 0;
    int right = 0;
    int sub_len = 0;
    int max_len = 0;

    int char_to_pos[ASCII_MAX];
    memset(char_to_pos, -1, ASCII_MAX * sizeof(int));

    int LEN = strlen(s);

    while(right < LEN){
        if((char_to_pos[s[right]] != -1) && (char_to_pos[s[right]] >= left)){
            left = char_to_pos[s[right]] + 1;
        }
        char_to_pos[s[right]] = right;
        right++;
        sub_len = right - left;
        if(sub_len > max_len){
            max_len = sub_len;
        }

    }

    return max_len;
}