class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int counter = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                counter++;
                nums[i] = nums[j]; 
                j++;
            } else
                j++;
        }
        return counter;
    }
};