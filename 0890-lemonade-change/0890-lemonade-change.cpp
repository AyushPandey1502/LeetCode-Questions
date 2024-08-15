class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 = 0, change10 = 0;

        for (int bill : bills) {
            if (bill == 5) {
                change5++;
            } else if (bill == 10) {
                if (change5 > 0) {
                    change5--;
                    change10++;
                } else {
                    return false;
                }
            } else {
                if (change10 > 0 && change5 > 0) {
                    change10--;
                    change5--;
                } else if (change5 >= 3) {
                    change5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
