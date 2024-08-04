class Solution {
public:
    const int MOD = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = (sum + nums[j]) % MOD;
                vec.push_back(sum);
            }
        }
        sort(vec.begin(), vec.end());
        int result = 0;
        for(int i = left - 1; i < right; i++) {
            result = (result + vec[i]) % MOD;
        }
        
        return result;
    }
};
