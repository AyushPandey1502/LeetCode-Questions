class Solution {
public:
    int totalMoney(int n) {
        int result = 0, weekStart = 1, day = 0;
        while (day < n) {
            for (int i = 0; i < 7 && day < n; i++) {
                result += weekStart + i;
                day++;
            }
            weekStart++;
        }
        return result;
    }
};
