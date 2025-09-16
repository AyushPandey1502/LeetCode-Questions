class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            while (!result.empty()) {
                int top = result.back(), g = __gcd(top, num);
                if (g == 1) break;
                result.pop_back();
                long long merged = (1LL * top / g) * num;
                num = (int)merged;
            }
            result.push_back(num);
        }
        return result;
    }
};
