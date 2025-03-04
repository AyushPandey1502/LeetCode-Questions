class Solution {
public:
    bool checkPowersOfThree(int n) {
        int maxExp = 0;
        while(pow(3, maxExp) < n) maxExp++;
        while(n > 0){
            if(n >= pow(3, maxExp)) n -= pow(3, maxExp);
            if(n >= pow(3, maxExp)) return false;
            maxExp--;
        }
        return true;
    }
};