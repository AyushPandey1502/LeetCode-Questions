class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n > 1){
            int remainder = n % 3;
            if(remainder > 0 && remainder < 3) return false;
            n /= 3;
        }
        return true;
    }
};