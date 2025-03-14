class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size(), result = 0;
        int left = 1, right = *max_element(candies.begin(), candies.end());

        auto check = [&](int mid) {
            long long count = 0;
            for(int i = 0; i < n; i++) count += candies[i] / mid;
            return count >= k;
        };

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(mid)) {
                result = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return result;
    }
};
