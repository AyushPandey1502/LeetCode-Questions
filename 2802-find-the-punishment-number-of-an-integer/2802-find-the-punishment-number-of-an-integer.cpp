class Solution {
public:
    bool checkWays(int sq, int currSum, int num) {
        if (sq == 0) return currSum == num;
        if (currSum > num) return false;

        int mod = 10;
        while (mod <= sq * 10) { 
            if (checkWays(sq / mod, currSum + (sq % mod), num)) return true;
            mod *= 10;
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (checkWays(sq, 0, i)) count += sq;
        }
        return count;
    }
};
