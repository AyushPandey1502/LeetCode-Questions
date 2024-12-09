class Solution {
public:
    void buildSegTree(int i, int left, int right, vector<int>& nums, vector<int>& segTree) {
        if (left == right) {
            segTree[i] = (left + 1 < nums.size() && (nums[left] % 2 == nums[left + 1] % 2)) ? 1 : 0;
            return;
        }
        int mid = (left + right) / 2;
        buildSegTree(2 * i + 1, left, mid, nums, segTree);
        buildSegTree(2 * i + 2, mid + 1, right, nums, segTree);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int querySum(int i, int start, int end, int left, int right, vector<int>& segTree) {
        if (end < left || start > right) return 0; 
        if (start <= left && right <= end) return segTree[i]; 
        int mid = (left + right) / 2;
        int leftSum = querySum(2 * i + 1, start, end, left, mid, segTree);
        int rightSum = querySum(2 * i + 2, start, end, mid + 1, right, segTree);
        return leftSum + rightSum;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> result;
        if (n == 1) {
            for (auto& query : queries) {
                result.push_back(true);
            }
            return result;
        }
        
        vector<int> segTree(4 * n, 0);
        buildSegTree(0, 0, n - 2, nums, segTree);

        for (auto& query : queries) {
            int from = query[0], to = query[1];
            if (from == to) {
                result.push_back(true);
                continue;
            }
            int mismatches = querySum(0, from, to - 1, 0, n - 2, segTree);
            result.push_back(mismatches == 0);
        }
        return result;
    }
};
