class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int rem = nums[0] % 2;
        int odd = 0;
        int even = 0;
        int both = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            if (num % 2 == rem) {
                both++;
                rem = !rem;
            }
        }
        return max(both, max(even, odd));
    }
};