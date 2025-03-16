class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 1, high = 1e14;
        long long result = 0;

        auto check = [&](long long mid) {
            long long count = 0;
            for(int i = 0; i < n; i++){
                count += (long long)sqrt(mid / ranks[i]);
                if (count >= cars) return true;
            }
            return count >= cars;
        };

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(mid)){
                result = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return result;
    }
};
