class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long org = x, num = 0;
        while(x){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return org == num;
    }
};