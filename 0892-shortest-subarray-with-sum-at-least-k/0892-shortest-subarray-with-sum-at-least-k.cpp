class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0); 
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        deque<int> deque; 
        int result = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while (!deque.empty() && prefixSum[i] - prefixSum[deque.front()] >= k) {
                result = min(result, i - deque.front());
                deque.pop_front();
            }
            while (!deque.empty() && prefixSum[i] <= prefixSum[deque.back()]) {
                deque.pop_back();
            }
            deque.push_back(i);
        }
        return result == INT_MAX ? -1 : result;
    }
};
