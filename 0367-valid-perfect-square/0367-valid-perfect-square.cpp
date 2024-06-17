class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
            return true;

        long left = 2, right = num / 2, mid, guessSquared;

        while (left <= right) {
            mid = left + (right - left) / 2;
            guessSquared = mid * mid;

            if (guessSquared == num) {
                return true;
            } else if (guessSquared > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
