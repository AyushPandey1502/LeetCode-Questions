class Solution {
public:
    int minChanges(int n, int k) {
        int result = 0;
        while (n > 0 || k > 0) {
            int bitN = n & 1;
            int bitK = k & 1;

            if (!bitN && bitK) {
                return -1;
            } else if (bitN != bitK) {
                result++;
            }
            n >>= 1;
            k >>= 1;
        }

        return result;
    }
};
