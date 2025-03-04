class Solution {
public:
    bool isPowerOfThree(int n) {
        int exp = 0;
        while(pow(3, exp) < n) exp++;
        return (n == (pow(3, exp)));
    }
};