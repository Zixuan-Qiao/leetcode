class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i = digits.size() - 1; i > 0; i--) {
            if(digits[i] != 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }

        if(digits[0] != 9) {
            digits[0] += 1;
            return digits;
        } else {
            deque<int> num{digits.cbegin(), digits.cend()};
            num[0] = 0;
            num.push_front(1);
            return vector<int>{num.cbegin(), num.cend()};
        } 
    }
};