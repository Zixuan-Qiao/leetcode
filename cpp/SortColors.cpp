class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        // 3 way partitioning algorithm
        while(mid <= high) {
            if(nums[mid] < 1) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] > 1) {
                swap(nums[mid], nums[high]);
                high--;
            } else {
                mid++;
            }
        }
    }
};