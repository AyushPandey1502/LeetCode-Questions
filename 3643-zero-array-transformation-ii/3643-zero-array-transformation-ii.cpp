class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        int left = 1, right = q;

        if(all_of(nums.begin(), nums.end(), [](int x){return x == 0;})) return 0;

        auto check = [&](int mid) {
            vector<int> diffArr(n + 1, 0);
            for (int i = 0; i < mid; i++) {
                int start = queries[i][0];
                int end = queries[i][1];
                int val = queries[i][2];
                diffArr[start] += val;
                diffArr[end + 1] -= val;
            }
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += diffArr[i];
                if (sum < nums[i]) return false; 
            }
            return true;
        };

        if (!check(q)) return -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }
};
