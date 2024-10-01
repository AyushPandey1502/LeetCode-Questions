class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long result = 0;
        unordered_map<int, int> map;
        for (int it : hours) {
            int rem = it % 24;
            map[rem]++;
        }
        
        for (int rem = 0; rem <= 12; rem++) {
            if (rem == 0 || rem == 12) {
                int count = map[rem];
                result += (long long)count * (count - 1) / 2;
            } else {
                int comp = 24 - rem;
                result += (long long)map[rem] * map[comp];
            }
        }
        return result;
    }
};
