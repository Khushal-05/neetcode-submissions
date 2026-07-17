class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0 , r = n-1;
        int maxArea = INT_MIN;

        while(l<r){
            int height = min(heights[l], heights[r]);
            int width = r-l;

            int area = height * width;
            if(area > maxArea){
                maxArea = area;
            }

            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};
