class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y) {
        ll result = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                result = result * x % MOD;
            }
            x = x * x % MOD;
        }
        return result;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), T = sqrt(n);
        vector<vector<vector<int>>> groups(T);
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) groups[k].push_back({l, r, v});
            else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1ll * nums[i] * v % MOD;
                }
            }
        }

        vector<ll> dif(n + T);
        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) continue;
            fill(dif.begin(), dif.end(), 1);
            for (auto& q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % MOD;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * pow(v, MOD - 2) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % MOD;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * dif[i] % MOD;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};