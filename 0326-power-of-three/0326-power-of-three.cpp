class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double log3 = log10(n) / log10(3);
        return ceil(log3) == floor(log3);
    }
};