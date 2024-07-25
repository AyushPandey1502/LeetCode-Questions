class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++) {
            left[i] = nums[low + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        while (i < n1) {
            nums[k++] = left[i++];
        }
        while (j < n2) {
            nums[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
