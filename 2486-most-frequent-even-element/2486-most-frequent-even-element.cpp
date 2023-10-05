class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        if (nums.empty()) return -1;
        
        unordered_map<int, int> count_map;
        int max_count = 0;
        int most_frequent_even = -1;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                count_map[num]++;
                if (count_map[num] > max_count || (count_map[num] == max_count && num < most_frequent_even)) {
                    max_count = count_map[num];
                    most_frequent_even = num;
                }
            }
        }
        return most_frequent_even;
    }
};
