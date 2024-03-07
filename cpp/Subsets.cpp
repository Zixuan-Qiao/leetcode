class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;

        exclude_include(nums, results, 0, current);

        return results;
    }

    void exclude_include(vector<int>& nums, vector<vector<int>>& results, int i, vector<int> current) {
        if(i >= nums.size()) {
            results.push_back(current);
            return ;
        }

        // exculding the current number
        exclude_include(nums, results, i + 1, current);

        // including the current number
        current.push_back(nums[i]);
        exclude_include(nums, results, i + 1, current);
    }
};