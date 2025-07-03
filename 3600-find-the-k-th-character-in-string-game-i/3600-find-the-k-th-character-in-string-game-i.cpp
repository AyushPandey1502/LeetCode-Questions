class Solution {
public:
    char kthCharacter(int k) {
        int t, result = 0;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) t--;
            k = k - (1 << t);
            result++;
        }
        return 'a' + result;
    }
};