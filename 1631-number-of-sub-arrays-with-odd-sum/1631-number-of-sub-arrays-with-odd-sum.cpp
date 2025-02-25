class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count = 0, prefixSum = 0, n = arr.size();
        int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            if(prefixSum % 2 == 0){
                count += oddCount;
                evenCount++;
            }else{
                count += evenCount;
                oddCount++;
            }
            count %= MOD;
        }
        return count;
    }
};