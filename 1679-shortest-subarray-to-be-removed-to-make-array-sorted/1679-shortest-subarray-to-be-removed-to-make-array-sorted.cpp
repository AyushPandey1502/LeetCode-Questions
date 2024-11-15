class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n = arr.size();
        int left = 0, right = n - 1;
        while(right > 0 && arr[right - 1] <= arr[right]){
            right--;
        }
        int result = right;
        while(left < right && (left == 0 || arr[left - 1] <= arr[left])){
            while(right < n && arr[left] > arr[right]){
                right++;
            }
            result = min(result, right - left - 1);
            left++;
        }
        return result;
    }
};