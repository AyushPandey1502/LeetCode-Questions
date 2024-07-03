class Solution {
public:
    int reverse(int x) {
        if(x >= INT_MAX || x <= INT_MIN) return 0;
        long result = 0;
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        while(x > 0){
            result = result * 10 + x % 10;
            x /= 10;
        }
        if(result >= INT_MAX || result <= INT_MIN) return 0;
        return sign * result;
    }
};