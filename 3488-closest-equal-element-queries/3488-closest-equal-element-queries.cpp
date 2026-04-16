class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        
        vector<int> result;
        for (int q : queries) {
            int val = nums[q];
            auto &vec = mpp[val];
            if (vec.size() == 1) {
                result.push_back(-1);
                continue;
            }
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int best = INT_MAX;
            if (it != vec.end()) {
                if (*it != q) {
                    int d = abs(*it - q);
                    best = min(best, min(d, n - d));
                } else if (it + 1 != vec.end()) {
                    int d = abs(*(it + 1) - q);
                    best = min(best, min(d, n - d));
                }
            }
            if (it != vec.begin()) {
                int idx = (it == vec.end() || *it != q) ? *(it - 1) : *(it - 1);
                if (idx != q) {
                    int d = abs(idx - q);
                    best = min(best, min(d, n - d));
                }
            }
            int first = vec.front();
            int last = vec.back(); 
            if (first != q) {
                int d = abs(first - q);
                best = min(best, min(d, n - d));
            }
            if (last != q) {
                int d = abs(last - q);
                best = min(best, min(d, n - d));
            }
            result.push_back(best);
        }
        return result;
    }
};