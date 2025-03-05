class Solution {
public:
    long long coloredCells(int n) {
        if(n <= 1) return n;
        long long result = 1;
        for(int i = 2; i <= n; i++){
            result += 4 * (i-1);
        }
        return result;
    }
};