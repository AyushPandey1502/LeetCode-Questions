class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto it : nums) xorsum ^= it;
        unsigned diffBit = xorsum & -static_cast<unsigned>(xorsum);
        int num1 = 0, num2 = 0;
        for (auto it : nums) {
            if (it & diffBit) num1 ^= it;
            else num2 ^= it;
        }
        return {num1, num2};
    }
};
