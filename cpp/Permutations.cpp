class Solution {
public:
    void expand(vector<vector<int>>& result, vector<bool>& used, vector<int>& array, vector<int>& nums) {
        if(array.size() == nums.size()) {
            result.push_back(array);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == true) {
                continue;
            }
            array.push_back(nums[i]);
            used[i] = true;
            expand(result, used, array, nums);
            array.pop_back();
            used[i] = false; 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> array;

        expand(result, used, array, nums);

        return result;
    }
};