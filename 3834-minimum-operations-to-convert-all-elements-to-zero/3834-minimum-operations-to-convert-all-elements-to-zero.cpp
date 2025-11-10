class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int result = 0;
        for (auto it : nums) {
            while (!s.empty() && s.back() > it) s.pop_back();
            if (it == 0) continue;
            if (s.empty() || s.back() < it) {
                result++;
                s.push_back(it);
            }
        }
        return result;
    }
};