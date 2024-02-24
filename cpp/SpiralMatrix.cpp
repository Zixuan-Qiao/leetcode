class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        std::vector<int> result;
        
        while(top <= bottom && left <= right) {

            // top row
            for(int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }

            if (top == bottom) {
			    break;
		    }

            // right colomn
            for(int i = top + 1; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }

            if (left == right) {
			    break;
		    }

            // bottom row
            for(int j = right - 1; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }

            // left colomn
            for(int i = bottom - 1; i > top; i--) {
                result.push_back(matrix[i][left]);
            }

            top++;
            left++;
            bottom--;
            right--;
        }

        return result;
    }
};