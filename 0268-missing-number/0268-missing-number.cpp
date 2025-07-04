// MOST OPTIMAL SOLUTION
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR1 = 0, XOR2 = 0;
        for(int i = 0; i < n; i++){
            XOR1 = XOR1 ^ nums[i];
            XOR2 = XOR2 ^ (i + 1);
        }
        return XOR1 ^ XOR2;
    }
};