// OPTIMAL APPROACH:
// TIME COMPLEXITY : O(N*LOGN)
// SPACE COMPLEXITY : O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int minNumElem = n / 3 + 1;
        unordered_map<int, int> freq;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] == minNumElem) {
                result.push_back(nums[i]);
            }
            if (result.size() == 2)
                break;
        }
        return result;
    }
};