class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int minNumElem = n / 3;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (result.empty() ||
                (result.size() > 0 && nums[i] != result.back())) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j])
                        count++;
                }
                if (count > minNumElem) {
                    result.push_back(nums[i]);
                }
                if (result.size() == 2)
                    break;
            }
        }
        return result;
    }
};