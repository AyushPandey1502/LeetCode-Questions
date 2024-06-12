class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (int num : nums) {
            count[num]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i] > 0) {
                nums[index++] = i;
                count[i]--;
            }
        }
    }
};