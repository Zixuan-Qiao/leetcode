class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<set<int>> record{set<int>(), set<int>()};

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    record[0].insert(i);
                    record[1].insert(j);
                }
            }
        }

        for(auto i : record[0]){
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }

        for(auto j : record[1]){
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
};