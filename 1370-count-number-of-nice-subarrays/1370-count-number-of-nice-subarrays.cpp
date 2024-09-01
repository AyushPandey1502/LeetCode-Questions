class Solution {
public:
    int countSubArray(vector<int>& nums, int goal){
        int left = 0, right = 0, count = 0, oddCount = 0;
        
        while(right < nums.size()){
            if(nums[right] % 2 == 1) oddCount++;
            while(oddCount > goal){
                if(nums[left] % 2 == 1) oddCount--;
                left++;
            }
            
            count += (right - left + 1);
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubArray(nums, k) - countSubArray(nums, k - 1);
    }
};
