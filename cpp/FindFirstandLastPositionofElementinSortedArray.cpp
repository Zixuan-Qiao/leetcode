class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> results = {-1, -1};
        if (nums.empty())
            return results;
        // modified binary search
        // expend range and continue search when target is found instead of terminate
        int low = 0, high = nums.size() - 1;
        int mid;
        // find lower bound
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == nums[mid]) {
                results[0] = mid;
                high = mid - 1;
            } else if (target > nums[mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        // find upper bound
        low = 0;
        high = nums.size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == nums[mid]) {
                results[1] = mid;
                low = mid + 1;
            } else if (target > nums[mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return results;
    }
};