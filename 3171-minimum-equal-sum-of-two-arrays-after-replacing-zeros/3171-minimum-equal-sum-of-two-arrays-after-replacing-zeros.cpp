class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int n : nums1) {
            if (n == 0) zero1++;
            else sum1 += n;
        }

        for (int n : nums2) {
            if (n == 0) zero2++;
            else sum2 += n;
        }

        long long minSum1 = sum1 + zero1 * 1;
        long long minSum2 = sum2 + zero2 * 1;
        if (minSum1 == minSum2) return minSum1;

        if (minSum1 < minSum2) {
            long long diff = minSum2 - minSum1;
            if (diff <= (long long)(zero1) * (INT_MAX - 1)) return minSum2;
            else return -1;
        } else {
            long long diff = minSum1 - minSum2;
            if (diff <= (long long)(zero2) * (INT_MAX - 1)) return minSum1;
            else return -1;
        }
    }
};
