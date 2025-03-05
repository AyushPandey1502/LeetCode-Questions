class Solution {
public:
    long long coloredCells(int n) {
        if(n <= 1) return n;
        long long result = 1 + 2LL * n * (n - 1);
        return result;
    }
};