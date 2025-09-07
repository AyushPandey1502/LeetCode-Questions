class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), (k - 1) / 2);
        
        for (int i = k; ; i++) {
            if (k % 2 == 1) result.push_back(*mid);
            else result.push_back(((long long)*mid + *next(mid)) / 2.0);
            if (i == nums.size()) break;
            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;
            if (nums[i - k] <= *mid) mid++; 
            window.erase(window.lower_bound(nums[i - k]));
        }
        return result;
    }
};
