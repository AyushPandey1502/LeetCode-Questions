class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int result = 0;
        for (int curr = 2; curr < n; curr++) {
            int start = 0;
            int end = curr - 1;

            while (start < end) {
                int pairSum = arr[start] + arr[end];

                if (pairSum > arr[curr]) end--;
                else if (pairSum < arr[curr]) start++;
                else {
                    dp[end][curr] = dp[start][end] + 1;
                    result = max(dp[end][curr], result);
                    end--;
                    start++;
                }
            }
        }
        return result == 0 ? 0 : result + 2;
    }
};