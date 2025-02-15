// TIME COMPLEXITY : O(n * 2^(log(n*n) + 1))
// SPACE COMPLEXITY : O(log(n * n))

class Solution {
public:
    bool checkWays(int sq, int currSum, int num){
        if(sq == 0) return currSum == num;
        int mod = 10;
        for(int i = 0; i <= 3; i++){
            if(checkWays(sq / mod, currSum + (sq % mod), num)) return true;
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
