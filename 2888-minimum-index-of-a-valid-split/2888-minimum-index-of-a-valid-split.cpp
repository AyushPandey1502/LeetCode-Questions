class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int it : nums) freq[it]++;
        
        int x = -1, count = 0;
        for (auto [key, value] : freq) {
            if (value > n / 2) {
                x = key;
                count = value;
                break;
            }
        }
        
        if (x == -1) return -1; 

        int left = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == x) left++;
            int right = count - left;
            if (2 * left > (i + 1) && 2 * right > (n - i - 1)) return i;
        }
        return -1;
    }
};
