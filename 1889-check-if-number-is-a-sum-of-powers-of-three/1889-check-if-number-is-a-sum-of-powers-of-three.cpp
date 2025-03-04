class Solution {
public:
    bool check(int n, int p){
        if(n == 0) return true;
        if(pow(3, p) > n) return false;
        return check(n - pow(3, p), p+1) || check(n, p+1);
    }

    bool checkPowersOfThree(int n) {
        return check(n, 0);
    }
};