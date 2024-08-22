class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int shift = 0;
        while(num > 0) {
            int dig = !(num & 1);
            result |= (dig << shift);
            num = num >> 1;
            shift++;
        }
        return result;
    }
};
