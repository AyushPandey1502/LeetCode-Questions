class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less = 0, equal = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) less++;
            else if(nums[i] == pivot) equal++;
        }
        int ls = 0, eq = less, gr = less + equal;
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) result[ls++] = nums[i];
            else if(nums[i] == pivot) result[eq++] = nums[i];
            else result[gr++] = nums[i]; 
        }
        return result;
    }
};
