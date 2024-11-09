class Solution {
public:
    long long minEnd(int n, int x) {
        long long last = 0, curr = 0;
        while (n--) {
            curr = (last | x);
            last = curr + 1;
        }
        return curr;
    }
};