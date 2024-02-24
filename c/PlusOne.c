/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    for(int i = digitsSize - 1; i > 0; i--) {
        if(digits[i] != 9) {
            digits[i] += 1;
            int *result = (int*)malloc(digitsSize * sizeof(int));
            for(int j = 0; j < digitsSize; j++) {
                result[j] = digits[j];
            }
            *returnSize = digitsSize;
            return result;
        } else {
            digits[i] = 0;
        }
    }

    if(digits[0] != 9) {
        digits[0] += 1;
        int *result = (int*)malloc(digitsSize * sizeof(int));
        for(int j = 0; j < digitsSize; j++) {
            result[j] = digits[j];
        }
        *returnSize = digitsSize;
        return result;
    } else {
        int *result = (int*)malloc((digitsSize + 1) * sizeof(int));
        for(int j = 1; j < digitsSize; j++) {
            result[j + 1] = digits[j];
        }
        result[0] = 1;
        result[1] = 0;
        *returnSize = digitsSize + 1;
        return result;
    } 
}