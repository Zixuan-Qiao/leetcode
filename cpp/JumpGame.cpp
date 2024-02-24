class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_distance = 0;
        int cur_distance = 0;

        if(nums.size() == 1) {
            return true;
        }
        
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0 && i == max_distance) {
                return false;
            }

            cur_distance = nums[i] + i;

            if(cur_distance > max_distance) {
                max_distance = cur_distance;
                if(max_distance >= nums.size() - 1) {
                    return true;
                }
            }
        }
        // won't be executed
        return true;
    }
};