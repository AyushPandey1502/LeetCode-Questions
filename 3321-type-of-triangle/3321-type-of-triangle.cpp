class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if((a + b > c) && (b + c > a) && (a + c > b)){
            unordered_set<int> sides(nums.begin(), nums.end());
            int size = sides.size();
            if(size == 3) return "scalene";
            else if(size == 2) return "isosceles";
            else return "equilateral";
        }else return "none";
    }
};