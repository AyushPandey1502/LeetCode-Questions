class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for (int num : nums2) freq[num]++;
    }

    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index] += val;
        freq[arr2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (int num : arr1) {
            result += freq[tot - num];
        }
        return result;
    }
};
