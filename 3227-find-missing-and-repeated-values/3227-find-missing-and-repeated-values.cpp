class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int XOR = 0;
        for (int i = 0; i < n * n; i++) {
            XOR ^= (i + 1); 
            XOR ^= grid[i / n][i % n]; 
        }
        int maskBit = XOR & -XOR;
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n * n; i++) {
            int val = grid[i / n][i % n];
            if (val & maskBit) num1 ^= val;
            else num2 ^= val;
        }
        for (int i = 1; i <= n * n; i++) {
            if (i & maskBit) num1 ^= i;
            else num2 ^= i;
        }
        for (int i = 0; i < n * n; i++) {
            if (grid[i / n][i % n] == num1) return {num1, num2};
        }
        return {num2, num1};
    }
};
