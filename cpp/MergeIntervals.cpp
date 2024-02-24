class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> results{intervals[0]};
        for(int i = 1; i < intervals.size(); i++) {
            if(results.back()[1] < intervals[i][0]) {
                results.push_back(intervals[i]);
            } else if(results.back()[1] < intervals[i][1]) {
                results.back()[1] = intervals[i][1];
            }
        }

        return results;

    }
};