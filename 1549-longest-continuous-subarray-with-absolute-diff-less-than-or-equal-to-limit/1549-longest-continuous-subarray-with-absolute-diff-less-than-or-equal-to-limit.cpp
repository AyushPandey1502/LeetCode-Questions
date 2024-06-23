class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P, vector<P>> maxPQ; // max-heap
        priority_queue<P, vector<P>, greater<P>> minPQ; // min-heap
        int i = 0, j = 0;
        int maxLen = 0;

        while (j < n) {
            maxPQ.push({nums[j], j});
            minPQ.push({nums[j], j});
            while (maxPQ.top().first - minPQ.top().first > limit) {
                i = min(maxPQ.top().second, minPQ.top().second) + 1;
                while (!maxPQ.empty() && maxPQ.top().second < i) {
                    maxPQ.pop();
                }
                while (!minPQ.empty() && minPQ.top().second < i) {
                    minPQ.pop();
                }
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
