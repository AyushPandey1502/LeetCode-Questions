class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), result = 0;
        int left = 0, right = n-1; 

        while(left < right){
            int len = min(height[left], height[right]);
            int width = right - left;
            result = max(result, len * width);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return result;
    }
};