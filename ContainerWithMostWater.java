class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int area = 0;
        int max_area = 0;

        while(l < r){
            if(height[l] <= height[r]){
                area = height[l] * (r - l);
                l++;
            } else {
                area = height[r] * (r - l);
                r--;
            }
            
            if(area > max_area){
                max_area = area;
            }
        }

        return max_area;
    }
}