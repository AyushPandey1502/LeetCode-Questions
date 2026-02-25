class Solution {
public:
    static int findWeight(int num) {
        int wt = 0;
        while (num > 0) {
            wt++;
            num &= (num - 1);
        }
        return wt;
    }
    
    static bool compare(int a, int b) {
        if (findWeight(a) == findWeight(b)) return a < b;
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};