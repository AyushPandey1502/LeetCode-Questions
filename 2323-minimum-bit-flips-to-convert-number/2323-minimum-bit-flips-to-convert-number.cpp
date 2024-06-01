class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int XOR = start ^ goal;
        while(XOR > 0){
            count += (XOR & 1);
            XOR = XOR >> 1;
        }
        return count;
    }
};