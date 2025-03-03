class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser, greater;
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) lesser.push_back(nums[i]);
            else if(nums[i] == pivot) count++;
            else greater.push_back(nums[i]);
        }
        vector<int> result(lesser.begin(), lesser.end());
        for(int i = 0; i < count; i++) result.push_back(pivot);
        result.insert(result.end(), greater.begin(), greater.end());
        return result;
    }
};