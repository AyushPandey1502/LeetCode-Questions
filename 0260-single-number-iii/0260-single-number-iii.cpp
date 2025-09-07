class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (auto it : nums) XOR ^= it;
        unsigned diffBit = XOR & -static_cast<unsigned>(XOR);
        int num1 = 0, num2 = 0;
        for (auto it : nums) {
            if (it & diffBit) num1 ^= it;
            else num2 ^= it;
        }
        return {num1, num2};
    }
};
