class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        while (true) {
            int i = rand() % n;
            int j = rand() % n;
            if (i != j && nums[i] == nums[j]) return nums[i];
        }
    }
};
