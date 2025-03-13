class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> diffArr(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diffArr[i] < nums[i]) {
                k++;
                if (k > queries.size()) return -1;
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];
                if (right >= i) {
                    diffArr[max(left, i)] += val;
                    diffArr[right + 1] -= val;
                }
            }
            sum += diffArr[i];
        }
        return k;
    }
};