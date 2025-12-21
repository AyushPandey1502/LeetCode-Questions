class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), result = 0;
        vector<bool> sorted(n - 1, false);
        for (int col = 0; col < m; col++) {
            bool flag = false;
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    flag = true;
                    break;
                }
            }
            if(flag) result++;
            else {
                for (int i = 0; i < n - 1; i++) {
                    if (strs[i][col] < strs[i + 1][col]) sorted[i] = true;
                }
            }
        }
        return result;
    }
};