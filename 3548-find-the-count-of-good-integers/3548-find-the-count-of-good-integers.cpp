class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long num = stoll(s);
            if (num % k == 0) {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long> fact(n + 1, 1);
        long long result = 0;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        for (auto s : dict) {
            vector<int> freq(10);
            for (char c : s) freq[c - '0']++;
            long long total = (n - freq[0]) * fact[n - 1];
            for (int x : freq) {
                total /= fact[x];
            }
            result += total;
        }
        return result;
    }
};