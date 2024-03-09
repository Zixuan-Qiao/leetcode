class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) {
            return heights[0];
        }

        stack<int> s;
        int max_area = 0;

        int i = 0;
        while(i < heights.size()) {
            while(!s.empty() && heights[s.top()] > heights[i]) {
                int j = s.top();
                s.pop();
                if(!s.empty()) {
                    max_area = max(max_area, heights[j] * (i - s.top() - 1));
                } else {
                    max_area = max(max_area, heights[j] * i);
                }                
            }
            s.push(i);
            i++;
        }

        i = s.top();
        while(!s.empty() && heights[s.top()] > 0) {
            int j = s.top();
            s.pop();
            if(!s.empty()) {
                max_area = max(max_area, heights[j] * (i - s.top()));
            } else {
                max_area = max(max_area, heights[j] * (i + 1));
            }                
        }

        return max_area;
    }
};