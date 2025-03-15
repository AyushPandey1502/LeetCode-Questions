class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    count++;
                    i++;
                }
            }
            if(count >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};