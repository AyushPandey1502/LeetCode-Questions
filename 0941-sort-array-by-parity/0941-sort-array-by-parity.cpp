class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int x, int y){return (x&1)<(y&1);}); return nums;
    }
};