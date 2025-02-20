class Solution {
public:
    int binToInt(string s) {
        int result = 0;
        for (char c : s) {
            result = (result << 1) | (c - '0');
        }
        return result;
    }

    string intToBin(int num, int n) {
        string result;
        for (int i = 0; i < n; i++) {
            result = char('0' + (num & 1)) + result;
            num >>= 1;
        }
        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for (auto num : nums) {
            seen.insert(binToInt(num));
        }
        for (int i = 0; i < (1 << n); i++) {
            if (!seen.count(i)) return intToBin(i, n);
        }
        return "";
    }
};
