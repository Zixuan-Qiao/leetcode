char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 0;
    while(1){
        if(strs[0][len] == '\0')
            return strs[0];
        for(int count = 1; count < strsSize; count++){
            if(strs[0][len] != strs[count][len]){
                strs[0][len] = '\0';
                return strs[0];
            }
        }
        len++;
    }
}