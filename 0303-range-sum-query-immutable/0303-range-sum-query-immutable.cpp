class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& arr) {
        int n = arr.size();
        prefixSum.resize(n);
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
    }
};
