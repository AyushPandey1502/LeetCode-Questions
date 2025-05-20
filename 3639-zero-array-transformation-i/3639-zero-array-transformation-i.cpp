class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);
        for (auto it : queries) {
            arr[it[0]]++;
            arr[it[1] + 1]--;
        }

        vector<int> count;
        int curr = 0;
        for (int it : arr){
            curr += it;
            count.push_back(curr);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (count[i] < nums[i]) return false;
        }
        return true;
    }
};