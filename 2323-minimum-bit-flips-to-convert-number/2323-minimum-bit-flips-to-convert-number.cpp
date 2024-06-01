class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int XOR = start ^ goal;
        return __builtin_popcount(XOR);
    }
};