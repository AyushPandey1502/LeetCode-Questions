class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> nums ;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) nums .push_back(y);
            else if (y == side) nums .push_back(side + x);
            else if (x == side) nums .push_back(side * 3LL - y);
            else nums .push_back(side * 4LL - x);
        }
        sort(nums .begin(), nums .end());

        auto check = [&](long long limit) -> bool {
            for (long long start : nums ) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(nums , cur + limit);
                    if (it == nums .end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0) return true;
            }
            return false;
        };

        long long low = 1, high = side;
        int result = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mid)) {
                low = mid + 1;
                result = mid;
            } else high = mid - 1;
        }
        return result;
    }
};