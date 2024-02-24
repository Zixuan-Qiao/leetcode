char* reverseWords(char* s) {
    
    char *result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    memset(result, '\0', strlen(s) + 1);
    int j = 0;

    int i = strlen(s) - 1;
    int len = 0;

    while(i >= 0) {
        if(s[i] == ' ') {
            i--;
        } else {
            while(i >= 0 && s[i] != ' ') {  // pay attention to the sequence of condition, i >= 0 has to be in the front
                len++;
                i--;
            }
            for(int k = 0; k < len; k++) {
                result[j] = s[i + k + 1];
                j++;
            }
            result[j] = ' ';
            j++;
            len = 0;
        }
    }

    result[j - 1] = '\0';

    return result;
}