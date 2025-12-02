class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        long long result = 0, sum = 0;
        unordered_map<int, int> mpp;
        for(auto it : points) mpp[it[1]]++;
        for(auto [_, it] : mpp){
            long long edge = (long long)it * (it - 1) / 2;
            result = (result + (edge * sum) % MOD) % MOD;
            sum = (sum + edge) % MOD;
        }
        return result;
    }
};