class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int result = 0;
        k--;
        for (int i = __lg(k); i >= 0; i--) {
            if (k >> i & 1) {
                result += operations[i];
            }
        }
        return 'a' + (result % 26);
    }
};