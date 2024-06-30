class Solution {
public:
    bool canFormTriangle(int red, int blue, int height) {
        int count = 0;
        for (int i = 1; i <= height; i++) {
            count += i;
            if (i % 2 == 1) {
                red -= i;
            } else {
                blue -= i;
            }
            if (red < 0 || blue < 0)
                return false;
        }
        return true;
    }

    int maxHeightOfTriangle(int red, int blue) {
        int left = 0, right = 1;
        while ((right * (right + 1)) / 2 <= red + blue) {
            right++;
        }
        right--;

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canFormTriangle(red, blue, mid) ||
                canFormTriangle(blue, red, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};