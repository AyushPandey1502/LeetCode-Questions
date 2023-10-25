class Solution {
public:
    void radixSort(vector<int>& nums, int n) {
        int min_num = *min_element(nums.begin(), nums.end());
        if (min_num < 0) {
            for (int& num : nums) {
                num += abs(min_num);
            }
        }
        int max_num = *max_element(nums.begin(), nums.end());
        for (int pos = 1; max_num / pos > 0; pos *= 10) {
            countSort(nums, n, pos);
        }

        if (min_num < 0) {
            for (int& num : nums) {
                num -= abs(min_num);
            }
        }
    }

    void countSort(vector<int>& nums, int n, int pos) {
        vector<int> count(10, 0);
        vector<int> newArray(n);

        for (int i = 0; i < n; i++) {
            count[(nums[i] / pos) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            newArray[--count[(nums[i] / pos) % 10]] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = newArray[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        radixSort(nums, size);
        return nums;
    }
};
