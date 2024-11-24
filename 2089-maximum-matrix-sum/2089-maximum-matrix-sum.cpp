class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negativeCount = 0;
        long long totalSum = 0;
        int minElement = INT_MAX;

        for (auto row : matrix) {
            for (auto value : row) {
                if (value < 0) {
                    negativeCount++;
                    value = -value;
                }
                totalSum += value;
                minElement = min(minElement, value);
            }
        }

        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minElement;
        }
        return totalSum;
    }
};
