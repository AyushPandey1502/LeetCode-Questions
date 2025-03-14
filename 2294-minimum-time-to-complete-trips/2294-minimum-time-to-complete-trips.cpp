class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = (long long)totalTrips * *min_element(time.begin(), time.end());
        long long result = 0;

        auto check = [&](long long mid) {
            long long count = 0;
            for(int i = 0; i < time.size(); i++) count += mid / time[i];
            return count >= totalTrips;
        };

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return left;
    }
};
