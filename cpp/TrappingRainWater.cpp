class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();      
        int l = 0;
        int r = n - 1;
        int l_max = height[0];
        int r_max = height[n - 1];

        int sum = 0;
        while(l <= r) {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if(l_max < r_max) {
                sum += l_max - height[l];
                l++;
            } else {
                sum += r_max - height[r];
                r--;
            }
        }
        return sum;
    }
};