class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, curr = 0;
        for (auto it : differences) {
            curr += it;
            x = min(x, curr);
            y = max(y, curr);
            if (y - x > upper - lower) return 0;
        }
        return (upper - lower) - (y - x) + 1;
    }
};