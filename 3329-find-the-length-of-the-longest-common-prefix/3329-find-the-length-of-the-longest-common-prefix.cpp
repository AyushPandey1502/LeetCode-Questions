class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        for (auto x : arr1) {
            while (x > 0) {
                set.insert(x);
                x /= 10;
            }
        }

        int maximum = INT_MIN;
        for (auto x : arr2) {
            while (x > 0) {
                if (set.find(x) != set.end()) {
                    maximum = max(maximum, static_cast<int>(to_string(x).size()));
                    break;
                }
                x /= 10;
            }
        }
        return (maximum == INT_MIN) ? 0 : maximum;
    }
};