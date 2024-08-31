class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int result = 0;
        int pos = 1;
        for(int i = 0; i < 4; i++){
            int dig1 = num1 % 10;
            int dig2 = num2 % 10;
            int dig3 = num3 % 10;
            int minDig = min({dig1, dig2, dig3});
            result += minDig * pos;
            pos *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return result;
    }
};