class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int ls = 0, gr = n-1;
        vector<int> result(n);
        for(int i = 0, j = n-1; i < n; i++, j--){
            if(nums[i] < pivot) result[ls++] = nums[i];
            if(nums[j] > pivot) result[gr--] = nums[j];
        }
        while(ls <= gr) result[ls++] = pivot;
        return result;
    }
};
