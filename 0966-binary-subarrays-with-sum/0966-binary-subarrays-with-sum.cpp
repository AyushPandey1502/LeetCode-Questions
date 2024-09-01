class Solution {
public:
    int countGoal(vector<int>& nums, int goal) {
        int left = 0, right = 0, sum = 0, count = 0;
        if(goal < 0) return 0; 
        while (right < nums.size()) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) {
            return countGoal(nums, 0);
        }
        return countGoal(nums, goal) - countGoal(nums, goal - 1);
    }
};
