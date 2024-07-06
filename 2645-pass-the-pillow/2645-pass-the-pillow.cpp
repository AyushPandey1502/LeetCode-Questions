class Solution {
public:
    int passThePillow(int n, int time) {
        int rotation = time / (n - 1);
        int remainder = time % (n - 1);
        if (rotation % 2 == 0) {
            return remainder + 1;
        } else {
            return n - remainder;
        }
    }
};
